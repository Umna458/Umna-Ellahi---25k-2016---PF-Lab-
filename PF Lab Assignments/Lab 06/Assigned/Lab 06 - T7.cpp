#include <stdio.h>

int main() {
    int base = 1;
    int exponent = 6;
    int result = 1;

    for (int i = 1; i <= exponent; i++) {
        result = result * base;
    }

    printf("%d raised to the power %d = %d\n", base, exponent, result);
    return 0;
}


