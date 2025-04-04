#include <stdio.h>

#define TAILLE_CHAINE 450
#define TAILLE_CONCAT 900

int main(void) {
    char chaine1[] = "Bonjour ESGI cours de C";
    char chaine2[] = " Vendredi apres midi ";
    char copie[TAILLE_CHAINE];
    char concat[TAILLE_CONCAT];

    int longueur = 0;
    while (chaine1[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur de chaine1 : %d\n", longueur);

    int i = 0;
    while (chaine1[i] != '\0') {
        copie[i] = chaine1[i];
        i++;
    }
    copie[i] = '\0';
    printf("Copie de chaine1 : %s\n", copie);

    i = 0;
    int j = 0;

    while (chaine1[i] != '\0') {
        concat[i] = chaine1[i];
        i++;
    }

    while (chaine2[j] != '\0') {
        concat[i] = chaine2[j];
        i++;
        j++;
    }
    concat[i] = '\0';

    printf("Concaténation : %s\n", concat);

    return 0;
}
