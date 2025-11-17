#include <stdio.h>

float book_value(float *price, int *stock);
float discount_policy(float value, int stock);


int main() {
    const int totalbooks = 5;
    float price[totalbooks];
    int stock[totalbooks];
    int i;
    float total;
    
    printf("Enter price and stock for 5 books:\n");
    for (i = 0; i < totalbooks; ++i) {
        printf("Book %d price: ", i+1); 
			scanf("%f", &price[i]);
        printf("Book %d stock: ", i+1); 
			scanf("%d", &stock[i]);
    }

    float totalinventory = 0.0;
    float (*calcvalue)(float*, int*) = (float (*)(float*, int*)) book_value;
    float (*calcdiscount)(float, int) = discount_policy;

    for (i = 0; i < totalbooks; ++i) {
        float bookvalue = calcvalue(&price[i], &stock[i]); 
        float final = calcdiscount(bookvalue, stock[i]);     
        printf("Book %d: Value before = Rs %.2f, after discount = Rs %.2f\n", i+1, bookvalue, final);
        total += final;
    }

    printf("Total library inventory value after discounts: Rs %.2f\n", total);
    return 0;
}

float book_value(float *price, int *stock) {
    return (*price) * (*stock);
}

float discount_policy(float value, int stock) {
    float discount = 0.0;
    
    if (stock < 3) 
		discount = 0.0;
    else if (stock <= 5) 
		discount = 0.10;
    else 
		discount = 0.20;
		
    return value - value * discount;
}


