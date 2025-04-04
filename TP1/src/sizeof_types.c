#include <stdio.h>
int main(void){
    printf("Size of char: %lu bytes\n", sizeof(unsigned char));
    printf("Size of char: %lu bytes\n", sizeof(signed char));
    printf("Size of int: %lu bytes\n", sizeof(unsigned int));
    printf("Size of int: %lu bytes\n", sizeof(signed int));
    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Size of double: %lu bytes\n", sizeof(double));
    printf("Size of short: %lu bytes\n", sizeof(unsigned short));
    printf("Size of short: %lu bytes\n", sizeof(signed short));
    printf("Size of long int: %lu bytes\n", sizeof(unsigned long int));
    printf("Size of long int: %lu bytes\n", sizeof(signed long int));
    printf("Size of long long int: %lu bytes\n", sizeof(unsigned long long int));
    printf("Size of long long int: %lu bytes\n", sizeof(signed long long int));
    printf("Size of long double: %lu bytes\n", sizeof(long double));


    return 0;
}
