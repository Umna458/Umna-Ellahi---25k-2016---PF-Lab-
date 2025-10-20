#include <stdio.h>
int main () {
	int attempts;
	
	printf("Enter number of failed login attempts: ");
	scanf("%d", &attempts);
	
	if (attempts == 0) {
		printf("No suspicious actvity\n");
	}
	else if (attempts >= 1 && attempts <= 3) {
		printf("Warning: User may have forgotten password\n");
	}
	else if (attempts >= 4 && attempts <=6) {
		printf("Alert: Possible unauthorized access attempt\n");
	}
	else if (attempts > 6) {
		printf("Critical: Account Locked due to brute-force attempt\n");
	}
	return 0;
	

}
