#include <stdio.h>

int main() {
    int somme = 0;

    for (int i = 1; i <= 1000; i++) {
        if (i % 11 == 0) {
            continue;
        }

        if (i % 5 == 0 || i % 7 == 0) {
            somme += i;
          printf("Somme actuelle : %d\n", somme);
        }

        if (somme > 5000) {
            break;
          printf(" Arrêt de la boucle 5000.\n");
        }
    }
    printf("La somme finale est : %d\n", somme);

    return 0;
}
