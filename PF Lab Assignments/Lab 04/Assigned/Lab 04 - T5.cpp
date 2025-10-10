#include <stdio.h>
int main () {
	int monthly_usage, fam_count;
	
	printf("Enter your monthly water consumption (litres): ");
	scanf("%d", &monthly_usage);
	
	
	
	if (monthly_usage > 3000) {
		printf("Number of people in your family: ");
		scanf("%d", &fam_count); }
		if (fam_count > 6) {
			printf("Allowed: Large Family Exception");
		}
	else {
		printf("Fine Applied");
	}	
	
	return 0;
}







