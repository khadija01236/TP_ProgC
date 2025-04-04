#include <stdio.h>

int main() {
    int n;

    printf("Entrez le nombre de termes à générer : ");
    scanf("%d", &n);

    int U0 = 0, U1 = 1;

    if (n < 0) {
        printf("Veuillez entrer un nombre positif.\n");
        return 1;
    }

    printf("Suite de Fibonacci jusqu'à U%d :\n", n);

    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            printf("%d", U0);
        } else if (i == 1) {
            printf(", %d", U1);
        } else {
            int Un = U0 + U1;
            printf(", %d", Un);
            U0 = U1;
            U1 = Un;
        }
    }

    printf("\n");
    return 0;
}
