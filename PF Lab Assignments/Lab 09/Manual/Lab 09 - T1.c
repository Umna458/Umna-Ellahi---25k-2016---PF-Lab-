#include <stdio.h>

float calcBill(float unit);

int main() {
    float unit[10], bill[10], total = 0;
    float *ptr;   // pointer for traversing
    int i;

    printf("Enter energy consumption (in kW) for 10 houses:\n");
    for (i = 0; i < 10; i++) {
        printf("House %d: ", i + 1);
        scanf("%f", &unit[i]);
    }

    ptr = unit;   

    for (i = 0; i < 10; i++) {
        bill[i] = calcBill(*(ptr + i));  
        printf("Bill of House %d = Rs. %.2f\n", i + 1, bill[i]);
        total += bill[i];
    }

    printf("\nTotal revenue collected = Rs. %.2f\n", total);

    return 0;
}

float calcBill(float unit) {
    float bill;
    if (unit <= 100)
        bill = unit * 10;
    else
        bill = (100 * 10) + ((unit - 100) * 15);
    return bill;
}


