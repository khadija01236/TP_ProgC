#include <stdio.h>

int main() {
    int cpt = 5;

    if (cpt >= 10) {
        printf("La valeur de compteur doit être strictement inférieure à 10.\n");
        return 1;
    }

    for (int i = 1; i <= cpt; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 1 || i == cpt || j == 1 || j == i) {
                printf("* ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }

    return 0;
}
