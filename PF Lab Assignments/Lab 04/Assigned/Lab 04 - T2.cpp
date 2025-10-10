#include <stdio.h>
int main() {
	int monthly_usage;
	
	printf("Enter your monthly water consumption (litres): ");
	scanf("%d", &monthly_usage);
	
	if (monthly_usage <= 3000) {
	printf("Bill = PKR 500");
	}
	else {
		printf("Bill = PKR 1000");
	}
	return 0;
}

