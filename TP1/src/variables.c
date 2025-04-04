#include <stdio.h>

int main() {
    signed char c_signed = -65;
    unsigned char c_unsigned = 200;

    signed short s_signed = -12345;
    unsigned short s_unsigned = 45678;


      signed int i_signed = -100000;
    unsigned int i_unsigned = 300000;

    signed long int l_signed = -1000000L;
    unsigned long int l_unsigned = 2000000UL;

    signed long long int ll_signed = -9000000000LL;
    unsigned long long int ll_unsigned = 18000000000ULL;

    float f = 3.14f;

    double d = 3.1415926535;

    long double ld = 3.141592653589793238L;

    printf("char signé : %d\n", c_signed);
    printf("char non signé : %u\n", c_unsigned);

    printf("short signé : %hd\n", s_signed);
    printf("short non signé : %hu\n", s_unsigned);

    printf("int signé : %d\n", i_signed);
    printf("int non signé : %u\n", i_unsigned);

    printf("long int signé : %ld\n", l_signed);
    printf("long int non signé : %lu\n", l_unsigned);

    printf("long long int signé : %lld\n", ll_signed);
    printf("long long int non signé : %llu\n", ll_unsigned);

    printf("float : %f\n", f);
    printf("double : %lf\n", d);
    printf("long double : %Lf\n", ld);

    return 0;
}
