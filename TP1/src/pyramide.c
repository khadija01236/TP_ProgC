
#include <stdio.h>

int main() {
    int n = 5; // Hauteur de la pyramide
    int i, j;

    for (i = 1; i <= n; i++) {
        // Affichage des espaces
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Nombres croissants de 1 à i
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Nombres décroissants de i-1 à 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // Saut de ligne
        printf("\n");
    }

    printf("La pyramide a été générée avec succès.\n");

    return 0;
}
