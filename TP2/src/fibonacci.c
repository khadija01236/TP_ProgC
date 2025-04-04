#include <stdio.h>

int main(void) {
    int n = 10, a = 0, b = 1, i;

    for (i = 0; i < n; i++) {
        printf("%d ", a);
        int temp = a + b;
        a = b;
        b = temp;
    }

    printf("\n");
    return 0;
}
