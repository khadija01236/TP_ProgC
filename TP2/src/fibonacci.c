#include <stdio.h>

int main(void) {
    int n = 7; 
    int u0 = 0, u1 = 1, suivant;

    printf("Suite de Fibonacci jusqu'à U%d :\n", n);

    printf("%d, %d", u0, u1);

  for (int i = 2; i < n; i++) {
        suivant = u0 + u1;
        printf(", %d", suivant);
        u0 = u1;
        u1 = suivant;
    }

    printf("\n");
    return 0;
}
