#include <stdio.h>

int main() {
    int st_id = 2016, sum = 0, digit;

    while (st_id > 0) {
        digit = st_id % 10;
        sum += digit;
        st_id /= 10;
    }

    printf("Sum of digits (2016) = %d\n", sum);
    return 0;
}



