#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tableau[TAILLE];
    int i, nombre_a_chercher;
    int trouve = 0; // 0 = non trouvé, 1 = trouvé

    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    // Remplissage du tableau avec des valeurs aléatoires entre 1 et 1000
    for (i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % 1000 + 1;
    }

    // Affichage du tableau
    printf("Tableau :\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    // Demander à l'utilisateur le nombre à chercher
    printf("Entrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &nombre_a_chercher);

    // Recherche dans le tableau
    for (i = 0; i < TAILLE; i++) {
        if (tableau[i] == nombre_a_chercher) {
            trouve = 1;
            break;
        }
    }

    // Affichage du résultat
    if (trouve) {
        printf("\nRésultat : entier présent\n");
    } else {
        printf("\nRésultat : entier absent\n");
    }

    return 0;
}
