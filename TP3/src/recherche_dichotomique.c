#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

void trier_tableau(int tab[], int taille) {
    int i, j, temp;
    for (i = 0; i < taille - 1; i++) {
        for (j = 0; j < taille - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int recherche_dichotomique(int tab[], int taille, int valeur) {
    int debut = 0;
    int fin = taille - 1;
    int milieu;

    while (debut <= fin) {
        milieu = (debut + fin) / 2;

        if (tab[milieu] == valeur) {
            return 1; // trouvé
        } else if (tab[milieu] < valeur) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }

    return 0; 
}

int main() {
    int tableau[TAILLE];
    int i, valeur_a_chercher;

    srand(time(NULL));

    for (i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % 1000 + 1;
    }

    trier_tableau(tableau, TAILLE);

    printf("Tableau trié :\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    printf("Entrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &valeur_a_chercher);

    if (recherche_dichotomique(tableau, TAILLE, valeur_a_chercher)) {
        printf("\nRésultat : entier présent\n");
    } else {
        printf("\nRésultat : entier absent\n");
    }

    return 0;
}
