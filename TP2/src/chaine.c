#include <stdio.h>

int main(void) {
    char chaine1[] = "Hello";
    char chaine2[] = " World!";
    char copie[100];
    char concat[200];

    // 1. Calcul de la longueur de chaine1
    int longueur = 0;
    while (chaine1[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur de chaine1 : %d\n", longueur);
}
