#include <stdio.h>

int main() {
    int townA = 10000, townB = 8000;
    int year = 0;

    while (townB <= townA) {
        townA += 250;
        townB += 400;
        year++;
    }

    printf("It will take %d years for:\n", year);
    printf("Town A Population: %d\n", townA);
    printf("Town B Population: %d\n", townB);

    return 0;
}



