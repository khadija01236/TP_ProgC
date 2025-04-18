#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 11

int main() {
    int tab_int[TAILLE];
    float tab_float[TAILLE];

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Remplissage des tableaux avec des valeurs aléatoires
    int *p_int = tab_int;
    float *p_float = tab_float;

    for (int i = 0; i < TAILLE; i++) {
        *(p_int + i) = rand() % 100 + 1;               // Entiers entre 1 et 100
        *(p_float + i) = (float)(rand() % 1000) / 100; // Floats entre 0.00 et 9.99
    }

    // Affichage avant manipulation
    printf("Tableau d'entiers (avant) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", *(p_int + i));
    }
    printf("\n\n");

    printf("Tableau de floats (avant) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%.2f ", *(p_float + i));
    }
    printf("\n\n");

    // Multiplication par 3 pour les indices pairs
    for (int i = 0; i < TAILLE; i++) {
        if (i % 2 == 0) {
            *(p_int + i) = *(p_int + i) * 3;
            *(p_float + i) = *(p_float + i) * 3.0f;
        }
    }

    // Affichage après manipulation
    printf("Tableau d'entiers (après) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", *(p_int + i));
    }
    printf("\n\n");

    printf("Tableau de floats (après) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%.2f ", *(p_float + i));
    }
    printf("\n");

    return 0;
}
