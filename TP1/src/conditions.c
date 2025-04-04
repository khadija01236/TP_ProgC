#include <stdio.h>

int main(void) {
    int somme = 0;

    for (int i = 1; i <= 1000; i++) {
        if (i % 11 == 0) {
            continue;
        }

        if (i % 5 == 0 || i % 7 == 0) {
            if (somme + i > 5000) {
                break;
            }

            somme += i;
            printf("Somme actuelle : %d\n", somme);
        }
    }

    printf("La somme finale est : %d\n", somme);

    return 0;
}
