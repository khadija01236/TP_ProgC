// #include <stdio.h>

// #define TAILLE_CHAINE 450
// #define TAILLE_CONCAT 900

// int main(void) {
//     char chaine1[] = "Bonjour ESGI cours de langage C";
//     char chaine2[] = " Vendredi apres midi ";
//     char copie[TAILLE_CHAINE];
//     char concat[TAILLE_CONCAT];

//     int longueur = 0;
//     while (chaine1[longueur] != '\0') {
//         longueur++;
//     }
//     printf("Longueur de chaine1 : %d\n", longueur);

//     int i = 0;
//     while (chaine1[i] != '\0') {
//         copie[i] = chaine1[i];
//         i++;
//     }
//     copie[i] = '\0';
//     printf("Copie de chaine1 : %s\n", copie);

//     i = 0;
//     int j = 0;

//     while (chaine1[i] != '\0') {
//         concat[i] = chaine1[i];
//         i++;
//     }

//     while (chaine2[j] != '\0') {
//         concat[i] = chaine2[j];
//         i++;
//         j++;
//     }
//     concat[i] = '\0';

//     printf("Concaténation : %s\n", concat);

//     return 0;
// }





#include <stdio.h>

void main() {
    char chaine1[] = "Hello";
    char chaine2[] = "World !";
    int Length1 = 0;
    int Length2 = 0;

    // Calcul de la longueur de chaine1
    for (int i = 0; i < 1000; i++) {
        if (chaine1[i] == '\0') {
            Length1 = i;
            break;
        }
    }

    // Calcul de la longueur de chaine2
    for (int i = 0; i < 1000; i++) {
        if (chaine2[i] == '\0') {
            Length2 = i;
            break;
        }
    }

    // Déclaration de la chaîne finale avec +1 pour le '\0'
    char chaine_finale[Length1 + Length2 + 1];

    // Copie de chaine1
    for (int i = 0; i < Length1; i++) {
        chaine_finale[i] = chaine1[i];
    }

    // Copie de chaine2 à la suite
    for (int i = 0; i < Length2; i++) {
        chaine_finale[Length1 + i] = chaine2[i];
    }

    // Ajout du caractère de fin
    chaine_finale[Length1 + Length2] = '\0';

    // Affichage de la chaîne finale
    printf("%s\n", chaine_finale);

}
