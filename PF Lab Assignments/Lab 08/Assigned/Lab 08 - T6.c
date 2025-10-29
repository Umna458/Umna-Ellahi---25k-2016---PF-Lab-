#include <stdio.h>

int main() {
    int i, j;

    printf("=== Triangular Multiplication Pattern ===\n");
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }

    printf("\n=== Reversed Pattern ===\n");
    for (i = 5; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }

    return 0;
}

