#include <stdio.h>
#include <math.h>

int main() {
    double rayon = 5; 
    double aire, perimetre;

    aire = M_PI * rayon * rayon;
    perimetre = 2 * M_PI * rayon;

    // Affichage des résultats
    printf("Rayon du cercle : %f\n", rayon);
    printf("Aire du cercle : %f\n", aire);
    printf("Périmètre du cercle : %f\n", perimetre);

    return 0;
}
