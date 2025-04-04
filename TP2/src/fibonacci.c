#include <stdio.h>

int main(void) {
    int n = 7;
    int a = 0, b = 1, temp;

    for (int i = 0; i <= n; i++) {
        printf("%d", a);
        if (i < n) printf(", ");
        temp = a + b;
        a = b;
        b = temp;
    }

    printf("\n");
    return 0;
}
