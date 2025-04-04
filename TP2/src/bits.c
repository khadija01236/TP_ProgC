#include <stdio.h>

int main(void) {
    unsigned int d = 0x10001000;

    if (((d >> 28) & 1) && ((d >> 12) & 1)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
