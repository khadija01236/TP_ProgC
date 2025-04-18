#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tableau[TAILLE];
    int i, min, max;

    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    // Remplir le tableau avec des valeurs aléatoires entre 1 et 1000
    for (i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % 1000 + 1; // entre 1 et 1000
    }

    // Initialiser min et max avec la première valeur
    min = tableau[0];
    max = tableau[0];

    // Parcourir le tableau pour trouver le min et le max
    for (i = 1; i < TAILLE; i++) {
        if (tableau[i] < min) {
            min = tableau[i];
        }
        if (tableau[i] > max) {
            max = tableau[i];
        }
    }

    // Affichage des résultats
    printf("Le numéro le plus petit est : %d\n", min);
    printf("Le numéro le plus grand est : %d\n", max);

    return 0;
}
