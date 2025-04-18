#include <stdio.h>

int main() {
    // Déclaration des variables
    char c = 0xAB;
    short s = 0x1234;
    int i = 0xA47865FF;
    long int li = 0x12345678;
    long long int lli = 0x123456789ABCDEF0;
    float f = 2.0f;                  // manipulé via bits
    double d = 3.14;
    long double ld = 2.718281828459;

    // Déclaration des pointeurs
    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long int *pli = &li;
    long long int *plli = &lli;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    // Avant manipulation
    printf("AVANT MANIPULATION :\n");
    printf("Adresse de c : %p, Valeur : 0x%02X\n", (void*)pc, *pc);
    printf("Adresse de s : %p, Valeur : 0x%04X\n", (void*)ps, *ps);
    printf("Adresse de i : %p, Valeur : 0x%08X\n", (void*)pi, *pi);
    printf("Adresse de li : %p, Valeur : 0x%08lX\n", (void*)pli, *pli);
    printf("Adresse de lli : %p, Valeur : 0x%016llX\n", (void*)plli, *plli);

    // Pour float/double, afficher en hex via pointeur cast
    printf("Adresse de f : %p, Valeur (hex) : 0x%08X\n", (void*)pf, *(unsigned int*)pf);
    printf("Adresse de d : %p, Valeur (hex) : 0x%016llX\n", (void*)pd, *(unsigned long long*)pd);
    printf("Adresse de ld : %p, Valeur (approx) : %Le\n", (void*)pld, *pld);

    printf("\n--- MANIPULATION ---\n\n");

    *pc = 0xFF;
    *ps = 0x5678;
    *pi = 0xA47865FE;
    *pli = 0x87654321;
    *plli = 0x0FEDCBA987654321;
    *pf = 1.0f;
    *pd = 6.28;
    *pld = 3.141592653589;

    printf("APRÈS MANIPULATION :\n");
    printf("Adresse de c : %p, Valeur : 0x%02X\n", (void*)pc, *pc);
    printf("Adresse de s : %p, Valeur : 0x%04X\n", (void*)ps, *ps);
    printf("Adresse de i : %p, Valeur : 0x%08X\n", (void*)pi, *pi);
    printf("Adresse de li : %p, Valeur : 0x%08lX\n", (void*)pli, *pli);
    printf("Adresse de lli : %p, Valeur : 0x%016llX\n", (void*)plli, *plli);
    printf("Adresse de f : %p, Valeur (hex) : 0x%08X\n", (void*)pf, *(unsigned int*)pf);
    printf("Adresse de d : %p, Valeur (hex) : 0x%016llX\n", (void*)pd, *(unsigned long long*)pd);
    printf("Adresse de ld : %p, Valeur (approx) : %Le\n", (void*)pld, *pld);

    return 0;
}
