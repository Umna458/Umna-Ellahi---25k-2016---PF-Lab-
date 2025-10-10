#include <stdio.h>
int main () {
	int monthly_usage, saved_days;
	
	printf("Enter monthly water consumption (litres): ");
	scanf("%d", &monthly_usage);
	
	printf("Enter the number of days water was saved (litres/day): ");
	scanf("%d", &saved_days);
	
	if (monthly_usage < 2500 && saved_days > 10) {
    	printf("Bonus: PKR 300 Discount\n"); }
	else {
    	printf("No Bonus\n"); }
	
	return 0;	
	} 
	


