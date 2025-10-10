#include <stdio.h>
int main () {
	int monthly_fine, monthly_usage;
	
	printf("Enter monthly water consumption (litres): ");
	scanf("%d", &monthly_usage);
	
	if (monthly_usage <= 3000) {
		printf("No Fine");
	}
	else if (monthly_usage > 3000 && monthly_usage <= 5000) {
		printf("Fine = PKR 200");
	}
	else if (monthly_usage > 5000 && monthly_usage < 7000) {
		printf("Fine = PKR 500");
	}
	else if (monthly_usage == 7000) {
		printf("Fine = PKR 1000 + Water Supply Restricted");
	}
	
	return 0;
}




