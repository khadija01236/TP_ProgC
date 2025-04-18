#include <stdio.h>

// Fonction générique pour afficher les octets d'une variable
void afficher_octets(void *ptr, size_t taille) {
    unsigned char *octet = (unsigned char *)ptr;
    for (size_t i = 0; i < taille; i++) {
        printf("%02X ", octet[i]);
    }
    printf("\n");
}

int main() {
    short s = 0x0302;
    int i = 0x04030201;
    long int li = 0x0807060504030201;
    float f = 4.01f;
    double d = 1.0;
    long double ld = 1.0;

    printf("Octets de short :\n");
    afficher_octets(&s, sizeof(s));

    printf("\nOctets de int :\n");
    afficher_octets(&i, sizeof(i));

    printf("\nOctets de long int :\n");
    afficher_octets(&li, sizeof(li));

    printf("\nOctets de float :\n");
    afficher_octets(&f, sizeof(f));

    printf("\nOctets de double :\n");
    afficher_octets(&d, sizeof(d));

    printf("\nOctets de long double :\n");
    afficher_octets(&ld, sizeof(ld));

    return 0;
}
