#include <stdio.h>
int main () {
	int days = 0, savings = 0, daily_savings = 1;
	
	while (savings < 100) {
		days++;
		savings += daily_savings;
		daily_savings++;
	}
	
	printf("It took %d days to reach or exceed $100\n", days);
	return 0;
}


