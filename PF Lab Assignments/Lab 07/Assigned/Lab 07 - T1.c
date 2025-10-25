#include<stdio.h>
int main () {
	int product, voucher, i;
	float price[] = {249, 1100, 2100, 6700, 3000, 8000, 4560, 112, 900, 11000};
	float discount, discounted_price[10] , total = 0.0;
	
	for (i = 0; i < 10; i++) {
		if (price[i] < 1000) {
			discount = price[i] * 0.05;
			discounted_price[i] = price[i] - discount;
			total += discounted_price[i];
		}
		else if (price[i] >= 1000 && price[i] < 5000) {
			discount = price[i] * 0.10;
			discounted_price[i] = price[i] - discount;
			total += discounted_price[i];
		}
		else if (price[i] >= 5000) {
			discount = price[i] * 0.15;
			discounted_price[i] = price[i] - discount;
			total += discounted_price[i];
		}
		else 
		printf("Invalid Input\n");
		
		
	printf("Product %d: %.2f\n", i+1, discounted_price[i]);	
	}
	
	printf("Your total is: %.2f\n", total);
	
	if (total > 25000) {
		voucher = 1;
		printf("Congratulations! You have earned a Gold Voucher!\n");
	}
	else {
		voucher = 0;
		printf("You have not earned a Gold Voucher yet! Keep trying! :)\n");
	}
	
	return 0;
}



