#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_COULEURS 100
#define MAX_COULEURS_DISTINCTES 100

// Structure représentant une couleur RGBA
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Couleur;

// Structure pour stocker une couleur distincte et son nombre d’occurrences
typedef struct {
    Couleur couleur;
    int occurrences;
} CouleurCompteur;

// Fonction pour comparer deux couleurs
int comparer_couleurs(Couleur c1, Couleur c2) {
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}

// Fonction pour afficher une couleur
void afficher_couleur(Couleur c) {
    printf("0x%02X 0x%02X 0x%02X 0x%02X", c.r, c.g, c.b, c.a);
}

int main() {
    Couleur tableau[NB_COULEURS];
    CouleurCompteur couleurs_distinctes[MAX_COULEURS_DISTINCTES];
    int nb_distinctes = 0;

    // Initialisation aléatoire
    srand(time(NULL));

    // Remplissage du tableau avec des couleurs aléatoires
    for (int i = 0; i < NB_COULEURS; i++) {
        tableau[i].r = rand() % 256;
        tableau[i].g = rand() % 256;
        tableau[i].b = rand() % 256;
        tableau[i].a = rand() % 256;
    }

    // Comptage des couleurs distinctes
    for (int i = 0; i < NB_COULEURS; i++) {
        int trouve = 0;

        for (int j = 0; j < nb_distinctes; j++) {
            if (comparer_couleurs(tableau[i], couleurs_distinctes[j].couleur)) {
                couleurs_distinctes[j].occurrences++;
                trouve = 1;
                break;
            }
        }

        if (!trouve) {
            couleurs_distinctes[nb_distinctes].couleur = tableau[i];
            couleurs_distinctes[nb_distinctes].occurrences = 1;
            nb_distinctes++;
        }
    }

    // Affichage des couleurs distinctes avec leur nombre d’occurrences
    printf("Couleurs distinctes et leurs occurrences :\n\n");
    for (int i = 0; i < nb_distinctes; i++) {
        afficher_couleur(couleurs_distinctes[i].couleur);
        printf(" : %d\n", couleurs_distinctes[i].occurrences);
    }

    return 0;
}
