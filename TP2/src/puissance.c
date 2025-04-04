#include <stdio.h>

int main(void) {
    int a = 4;
    int b = 5;
    int resultat = 1; 

    for (int i = 0; i < b; i++) {
        resultat *= a; 
    }

    printf("%d à la puissance %d est : %d\n", a, b, resultat);

    return 0;
}
