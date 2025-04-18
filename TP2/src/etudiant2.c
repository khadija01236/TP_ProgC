#include <stdio.h>
#include <string.h>

#define NB_ETUDIANTS 5

// Structure Étudiant
struct Etudiant {
    char nom[15];
    char prenom[15];
    char adresse[100];
    float note_prog;
    float note_sys;
};

int main() {
    struct Etudiant etudiants[NB_ETUDIANTS];

    strcpy(etudiants[0].nom, "Jean");
    strcpy(etudiants[0].prenom, "Marie");
    strcpy(etudiants[0].adresse, "34 allee du gacet");
    etudiants[0].note_prog = 17.5;
    etudiants[0].note_sys = 15.0;

    strcpy(etudiants[1].nom, "Berger");
    strcpy(etudiants[1].prenom, "Alice");
    strcpy(etudiants[1].adresse, "25 avenue Victor Hugo");
    etudiants[1].note_prog = 11.0;
    etudiants[1].note_sys = 12.5;

    strcpy(etudiants[2].nom, "Sanchez");
    strcpy(etudiants[2].prenom, "Khadija");
    strcpy(etudiants[2].adresse, "18 boulevard de Rennes");
    etudiants[2].note_prog = 14.2;
    etudiants[2].note_sys = 16.0;

    strcpy(etudiants[3].nom, "Roux");
    strcpy(etudiants[3].prenom, "Pierre");
    strcpy(etudiants[3].adresse, "4 impasse des Acacias");
    etudiants[3].note_prog = 12.8;
    etudiants[3].note_sys = 14.2;

    strcpy(etudiants[4].nom, "Carpentier");
    strcpy(etudiants[4].prenom, "Bernard");
    strcpy(etudiants[4].adresse, "32 place de la République");
    etudiants[4].note_prog = 15.5;
    etudiants[4].note_sys = 16.3;

    // Affichage
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Étudiant %d :\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prénom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Note en Programmation en C : %f\n", etudiants[i].note_prog);
        printf("Note en Système d'exploitation : %f\n", etudiants[i].note_sys);
        printf("-------------------------------------\n");
    }

    return 0;
}
