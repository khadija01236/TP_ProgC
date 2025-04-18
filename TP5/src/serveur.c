/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>

#include "serveur.h"

int socketfd; // Déclaration globale de socketfd

/**
 * Cette fonction envoie un message (*data) au client (client_socket_fd)
 * @param client_socket_fd : Le descripteur de socket du client.
 * @param sdata : Le message à envoyer.
 * @return EXIT_SUCCESS en cas de succès, EXIT_FAILURE en cas d'erreur.
 */
int renvoie_message(int client_socket_fd, char *data)
{
  int data_size = write(client_socket_fd, (void *)data, strlen(data));

  if (data_size < 0)
  {
    perror("Erreur d'écriture");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

/**
 * Cette fonction lit les données envoyées par le client,
 * et renvoie un message en réponse saisi par l'utilisateur.
 * @param client_socket_fd : Le descripteur de socket du client.
 * @param data : Le message.
 * @return EXIT_SUCCESS en cas de succès, EXIT_FAILURE en cas d'erreur.
 */
// int recois_envoie_message(int client_socket_fd, char *data)
// {
//   printf("Message reçu: %s\n", data);

//   char reponse[1024];
//   printf("Tapez votre réponse au client : ");
//   fflush(stdout); // S'assurer que le message s'affiche avant l'entrée

//   if (fgets(reponse, sizeof(reponse), stdin) == NULL)
//   {
//     perror("Erreur de saisie");
//     return EXIT_FAILURE;
//   }

//   // Supprimer le saut de ligne (\n) ajouté par fgets
//   size_t len = strlen(reponse);
//   if (len > 0 && reponse[len - 1] == '\n')
//   {
//     reponse[len - 1] = '\0';
//   }

//   // Envoyer la réponse au client
//   return renvoie_message(client_socket_fd, reponse);
// }

int recois_envoie_message(int client_socket_fd, char *data)
{
  printf("Message reçu: %s\n", data);

  // Variables pour extraire l’opération et les opérandes
  char operateur;
  int a, b, resultat;
  char reponse[1024];

  // Exemple attendu : "+ 25 15"
  if (sscanf(data, "%c %d %d", &operateur, &a, &b) == 3)
  {
    switch (operateur)
    {
      case '+':
        resultat = a + b;
        break;
      case '-':
        resultat = a - b;
        break;
      case '*':
        resultat = a * b;
        break;
      case '/':
        if (b != 0)
          resultat = a / b;
        else
        {
          snprintf(reponse, sizeof(reponse), "Erreur : division par zéro.");
          return renvoie_message(client_socket_fd, reponse);
        }
        break;
      default:
        snprintf(reponse, sizeof(reponse), "Erreur : opérateur non reconnu.");
        return renvoie_message(client_socket_fd, reponse);
    }

    // Envoyer le résultat au client
    snprintf(reponse, sizeof(reponse), "Résultat : %d", resultat);
    return renvoie_message(client_socket_fd, reponse);
  }
  else
  {
    snprintf(reponse, sizeof(reponse), "Erreur : format invalide. Exemple attendu : + 25 15");
    return renvoie_message(client_socket_fd, reponse);
  }
}


/**
 * Gestionnaire de signal pour Ctrl+C (SIGINT).
 * @param signal : Le signal capturé (doit être SIGINT pour Ctrl+C).
 */
void gestionnaire_ctrl_c(int signal)
{
  printf("\nSignal Ctrl+C capturé. Sortie du programme.\n");

  // Fermer le socket si ouvert
  if (socketfd != -1)
  {
    close(socketfd);
  }

  exit(0); // Quitter proprement le programme.
}

/**
 * Gère la communication avec un client spécifique.
 *
 * @param client_socket_fd Le descripteur de socket du client à gérer.
 */
void gerer_client(int client_socket_fd)
{
  char data[1024];

  while (1)
  {
    // Réinitialisation des données
    memset(data, 0, sizeof(data));

    // Lecture des données envoyées par le client
    int data_size = read(client_socket_fd, data, sizeof(data));

    if (data_size <= 0)
    {
      // Erreur de réception ou déconnexion du client
      if (data_size == 0)
      {
        // Le client a fermé la connexion proprement
        printf("Client déconnecté.\n");
      }
      else
      {
        perror("Erreur de réception");
      }

      // Fermer le socket du client et sortir de la boucle de communication
      close(client_socket_fd);
      break;
    }

    recois_envoie_message(client_socket_fd, data);
  }
}

/**
 * Point d’entrée du programme serveur.
 */
int main()
{
  int bind_status;
  struct sockaddr_in server_addr;
  int option = 1;

  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("Impossible d'ouvrir une socket");
    return -1;
  }

  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  bind_status = bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (bind_status < 0)
  {
    perror("bind");
    return EXIT_FAILURE;
  }

  signal(SIGINT, gestionnaire_ctrl_c);

  listen(socketfd, 10);
  printf("Serveur en attente de connexions...\n");

  struct sockaddr_in client_addr;
  unsigned int client_addr_len = sizeof(client_addr);
  int client_socket_fd;

  while (1)
  {
    client_socket_fd = accept(socketfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket_fd < 0)
    {
      perror("accept");
      continue;
    }

    pid_t child_pid = fork();
    if (child_pid == 0)
    {
      close(socketfd);
      gerer_client(client_socket_fd);
      exit(0);
    }
    else if (child_pid < 0)
    {
      perror("fork");
      close(client_socket_fd);
    }
    else
    {
      close(client_socket_fd);
    }
  }

  return 0;
}
