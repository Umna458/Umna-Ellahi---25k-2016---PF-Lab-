#include <stdio.h>

int main() {
    double principal = 1000.0;
    double rate = 0.05;
    double amount;
    int year;
     
    printf("Year\tAmount\n");
    printf("----------------\n");

    for (year = 1; year <= 10; year++) {
        amount = principal;
        
        for (int i = 1; i <= year; i++) {
            amount = amount * (1 + rate);
        }

        printf("%d\t%.2lf\n", year, amount);
    }

    return 0;
}




