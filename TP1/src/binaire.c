#include <stdio.h>

void afficherBinaire(unsigned int n) {
    int i;
    int taille = sizeof(unsigned int) * 8;

    int bitTrouve = 0; 

    for (i = taille - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (bit == 1) {
            bitTrouve = 1;
        }
        if (bitTrouve) {
            printf("%d", bit);
        }
    }

    // Si le nombre est 0
    if (!bitTrouve) {
        printf("0");
    }

    printf("\n");
}

int main() {
    unsigned int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = sizeof(nombres) / sizeof(nombres[0]);

    for (int i = 0; i < taille; i++) {
        printf("Décimal : %u → Binaire : ", nombres[i]);
        afficherBinaire(nombres[i]);
    }

    return 0;
}
