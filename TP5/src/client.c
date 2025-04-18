/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> // Nécessaire pour inet_addr

#include "client.h"

/**
 * Fonction pour envoyer et recevoir un message depuis un client connecté à la socket.
 *
 * @param socketfd Le descripteur de la socket utilisée pour la communication.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_recois_message(int socketfd)
{
  char data[1024];

  // Réinitialisation des données
  memset(data, 0, sizeof(data));

  // Demande à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caractères): ");
  fgets(message, sizeof(message), stdin);

  // Supprimer le \n à la fin
  size_t len = strlen(message);
  if (len > 0 && message[len - 1] == '\n') {
    message[len - 1] = '\0';
  }

  // Préparer le message à envoyer
  strcpy(data, "message: ");
  strcat(data, message);

  // Envoyer le message
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("Erreur d'écriture");
    return -1;
  }

  // Lire la réponse du serveur
  memset(data, 0, sizeof(data));
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("Erreur de lecture");
    return -1;
  }

  // Affichage de la réponse
  printf("Message reçu: %s\n", data);

  return 0;
}

int main()
{
  int socketfd;
  struct sockaddr_in server_addr;

  // Création de la socket
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Configuration de l'adresse du serveur
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT); // PORT défini dans client.h
  server_addr.sin_addr.s_addr = inet_addr("10.0.29.4"); // IP de ton serveur

  // Connexion au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  // Boucle d’envoi/réception
  while (1)
  {
    envoie_recois_message(socketfd);
  }

  close(socketfd);
  return 0;
}
