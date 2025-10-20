#include<stdio.h>
int main() {
	
	int loyalty_points; 
	float discount;
	
	printf("Enter your loyalty points: ");
	scanf("%d", &loyalty_points);
	
	(loyalty_points > 1000) ? (discount = 0.20) : (discount = 0.05);
	
	printf("Your discount percentage is: %.2f", discount);
	
	return 0;
}




