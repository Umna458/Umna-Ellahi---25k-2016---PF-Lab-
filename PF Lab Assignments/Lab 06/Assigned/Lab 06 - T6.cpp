
#include <stdio.h>

int main() {
    int st_id = 2016, reverse = 0, digit;

    while (st_id > 0) {
        digit = st_id % 10;
        reverse = reverse * 10 + digit;
        st_id /= 10;
    }

    printf("Reversed number = %d\n", reverse);
    return 0;
}


