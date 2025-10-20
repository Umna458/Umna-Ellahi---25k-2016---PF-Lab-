#include <stdio.h>

int main() {
    int num = 7;
    int factorial = 1;

    for (int i = 1; i <= num; i++) {
        factorial = factorial * i;
    }

    printf("Factorial of %d = %d\n", num, factorial);
    return 0;
}




