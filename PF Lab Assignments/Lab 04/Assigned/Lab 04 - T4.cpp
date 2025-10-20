#include <stdio.h>
int main() {
	int code;
	
	printf("Enter the category code that meets your criteria\n");
	printf("(1) Low Usage Household\n");
	printf("(2) Average Household\n");
	printf("(3) High Usage Household\n");
	printf("(4) Excessive Usage Household\n");
	printf("\nEnter category code (1-4): ");
	scanf("%d", &code);
	 
	switch (code) {
		case 1: printf("Low Usage Household\n"); break;
		case 2: printf("Average Household\n"); break;
		case 3: printf("High Usage Household\n"); break;
		case 4: printf("Excessive Usage Household\n"); break;
		default: printf("Invalid Category Code\n"); break;
	}
	
	return 0;
}





