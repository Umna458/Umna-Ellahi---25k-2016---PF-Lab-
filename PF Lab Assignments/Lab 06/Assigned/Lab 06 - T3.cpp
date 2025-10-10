#include <stdio.h>
int main() {
	
    int second_last = 1;
    int last = 6;
    int num = 1, count = 0;

    printf("First 10 numbers divisible by %d and %d:\n", second_last, last);

    while (count < 10) {
        if (num % second_last == 0 && num % last == 0) {
            printf("%d ", num);
            count++;
        }
        num++;
    }

    return 0;
}




