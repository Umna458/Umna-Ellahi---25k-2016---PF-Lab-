#include <stdio.h>
int main () {
	int daily_usage;
	
	printf("Enter your daily water consumption (litres): ");
	scanf("%d", &daily_usage);
	
	if (daily_usage <= 100) {
	printf(" Efficient Usage");
	}
	else {
		printf("High Usage Detected");
	}
	return 0;
}


