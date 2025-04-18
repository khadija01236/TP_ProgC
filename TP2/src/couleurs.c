#include <stdio.h>

#define NB_COULEURS 10

struct Couleur {
    unsigned char rouge;
    unsigned char vert;
    unsigned char bleu;
    unsigned char alpha;
};

int main() {
    // Tableau de 10 couleurs
    struct Couleur couleurs[NB_COULEURS] = {
        {0xef, 0x78, 0x12, 0xff}, // Couleur 1
        {0x2c, 0xc8, 0x64, 0xff}, // Couleur 2
        {0x99, 0x33, 0xff, 0xaa}, // Couleur 3
        {0x00, 0x00, 0x00, 0xff}, // Couleur 4 (noir opaque)
        {0xff, 0xff, 0xff, 0x80}, // Couleur 5 (blanc semi-transparent)
        {0xdd, 0x22, 0x77, 0xee}, // Couleur 6
        {0x10, 0x20, 0x30, 0x40}, // Couleur 7
        {0xaa, 0xbb, 0xcc, 0xdd}, // Couleur 8
        {0x01, 0x02, 0x03, 0x04}, // Couleur 9
        {0xfe, 0xdc, 0xba, 0x98}  // Couleur 10
    };

    // Affichage
    for (int i = 0; i < NB_COULEURS; i++) {
        printf("Couleur %d :\n", i + 1);
        printf("Rouge : %d\n", couleurs[i].rouge);
        printf("Vert  : %d\n", couleurs[i].vert);
        printf("Bleu  : %d\n", couleurs[i].bleu);
        printf("Alpha : %d\n", couleurs[i].alpha);
        printf("-------------------------\n");
    }

    return 0;
}
