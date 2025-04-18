#include <stdio.h>

#define NB_PHRASES 10
#define TAILLE_MAX 100

// Fonction de comparaison de deux chaînes de caractères
int comparer_phrases(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0; // caractères différents
        }
        i++;
    }
    // Vérifie que les deux chaînes sont de même longueur
    return a[i] == '\0' && b[i] == '\0';
}

int main() {
    // Tableau de 10 phrases (tableau de tableaux de caractères)
    char phrases[NB_PHRASES][TAILLE_MAX] = {
        "Bonjour, comment ca va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journee.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent etre deroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est interessante.",
        "Les structures de donnees sont importantes.",
        "Programmer en C, c'est genial."
    };

    // Phrase à rechercher
    char recherche[TAILLE_MAX];

    // Saisie utilisateur
    printf("Entrez la phrase a rechercher :\n");
    fgets(recherche, TAILLE_MAX, stdin);

    // Supprimer le saut de ligne si présent
    int i = 0;
    while (recherche[i] != '\0') {
        if (recherche[i] == '\n') {
            recherche[i] = '\0';
            break;
        }
        i++;
    }

    // Recherche dans le tableau
    int trouve = 0;
    for (i = 0; i < NB_PHRASES; i++) {
        if (comparer_phrases(phrases[i], recherche)) {
            trouve = 1;
            break;
        }
    }

    // Affichage du résultat
    if (trouve) {
        printf("Phrase trouvee\n");
    } else {
        printf("Phrase non trouvee\n");
    }

    return 0;
}
