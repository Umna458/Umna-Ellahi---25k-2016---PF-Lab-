#include<stdio.h>
int main () {
	int rating, distance;
	
	printf("What is the driver rating? (1-5): ");
	scanf("%d", &rating);
	
	printf("What is the driver distance from passenger?: ");
	scanf("%d", &distance);
	
	if (rating >= 4 && distance <= 5) {
		printf("\nTop driver nearby\n");	
	}
	else if (rating >= 3 && distance <= 10) {
		printf("\nAverage driver assigned");
	}
	else {
		printf("\nNo suitable driver available");
	}
	
	return 0;
}


