#include <stdio.h>

int main(void) {
    int n = 7, a = 0, b = 1, i;

    for (i = 0; i <= n; i++) {
        printf("%d", a);
        if (i < n) printf(", ");

        int temp = a + b;
        a = b;
        b = temp;
    }
}
