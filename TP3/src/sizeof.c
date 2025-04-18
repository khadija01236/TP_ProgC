#include <stdio.h>

int main() {
    printf("La taille de int est : %lu octets\n", sizeof(int));
    printf("La taille de int* est : %lu octets\n", sizeof(int*));
    printf("La taille de int** est : %lu octets\n", sizeof(int**));

    printf("La taille de char est : %lu octets\n", sizeof(char));
    printf("La taille de char* est : %lu octets\n", sizeof(char*));
    printf("La taille de char** est : %lu octets\n", sizeof(char**));
    printf("La taille de char*** est : %lu octets\n", sizeof(char***));

    printf("La taille de float est : %lu octets\n", sizeof(float));
    printf("La taille de float* est : %lu octets\n", sizeof(float*));
    printf("La taille de float** est : %lu octets\n", sizeof(float**));
    printf("La taille de float*** est : %lu octets\n", sizeof(float***));

    printf("La taille de double est : %lu octets\n", sizeof(double));
    printf("La taille de double* est : %lu octets\n", sizeof(double*));

    printf("La taille de long int est : %lu octets\n", sizeof(long int));
    printf("La taille de long long int est : %lu octets\n", sizeof(long long int));
    printf("La taille de long double est : %lu octets\n", sizeof(long double));

    return 0;
}
