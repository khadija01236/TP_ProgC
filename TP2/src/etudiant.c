#include <stdio.h>

#define NB_ETUDIANTS 5

int main() {
    char noms[NB_ETUDIANTS][15] = {
        "Jean", "Berger", "Sanchez", "Roux", "Carpentier"
    };
    
    char prenoms[NB_ETUDIANTS][15] = {
        "Marie", "Alice", "Khadija", "Pierre", "Bernard"
    };
    
    char adresses[NB_ETUDIANTS][100] = {
        "34 allee du gacet", 
        "25 avenue Victor Hugo", 
        "18 boulevard de Rennes", 
        "4 impasse des Acacias", 
        "32 place de la République"
    };
    
    // Notes
    float notes_prog[NB_ETUDIANTS] = {17.5, 11.0, 14.2, 12.8, 15.5};
    float notes_sys[NB_ETUDIANTS] = {15.0, 12.5, 16.0, 14.2, 16.3};

    // Affichage
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Étudiant %d :\n", i + 1);
        printf("Nom : %s\n", noms[i]);
        printf("Prénom : %s\n", prenoms[i]);
        printf("Adresse : %s\n", adresses[i]);
        printf("Note en Programmation en C : %f\n", notes_prog[i]);
        printf("Note en Système d'exploitation : %f\n", notes_sys[i]);
        printf("-------------------------------------\n");
    }

    return 0;
}
