#include <stdio.h>
double apply_discount(float *prices, int count);
int main() {
    float prices[5];
    int n = 5, i;
    printf("Enter prices of 5 products:\n");
    for (i = 0; i < n; ++i) 
		scanf("%f", &prices[i]);

    float total = apply_discount(prices, n);

    printf("\nPrices after discount:\n");
    for (i = 0; i < n; ++i) {
        printf("Product %d: Rs %.2f\n", i + 1, *(prices + i)); 
    }
    printf("Total after discounts: Rs %.2f\n", total);
    return 0;
}

double apply_discount(float *prices, int count) {
    float total = 0.0;
    float discount = 0.0;
    int i;

    for ( i = 0; i < count; ++i) {
        float p = *(prices + i);
        
        if (p < 1000) 
			discount = 0.10;
        else if (p <= 5000) 
			discount = 0.15;
        else discount = 0.25;
        
        p = p - p * discount;
        *(prices + i) = p; 
        total += p;
    }
    return total;
}


