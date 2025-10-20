#include<stdio.h>
#include <string.h>
int main() {
	int ride_type, fare = 0;
	char distance[10], class_type[50];
	
	//Inputs for ride type
	printf("Choose your ride type\n");
	printf("(1) Economy\n");
	printf("(2) Business\n");
	printf("(3) Luxury\n");
	printf("Enter your choice: ");
	scanf("%d", &ride_type);
	
	
	
	switch(ride_type) {
		case 1:
			strcpy(class_type,"You got an Economy class ride");
			printf("Enter your distance (short/long): ");
			scanf("%s", &distance);
			
			if (strcmp(distance, "short") == 0) {
				fare = 100;
			}
			else if (strcmp(distance, "long") == 0) {
				fare = 300;
			}
			else {
				printf("\nInvalid input\n");
				return 1;
			}
			
			break;
		case 2:
			strcpy(class_type, "You got an Business class ride");
			printf("Enter your distance (short/long): ");
			scanf("%s", &distance);
			
			if (strcmp(distance, "short") == 0) {
				fare = 100;
			}
			else if (strcmp(distance, "long") == 0) {
				fare = 300;
			}
			else {
				printf("\nInvalid input\n");
				return 1;
			}
			
			break;
		case 3:
		    strcpy(class_type, "You got an Luxury class ride");
			printf("Enter your distance (short/long): ");
			scanf("%s", distance);
			
			if (strcmp(distance, "short") == 0) {
				fare = 100;
			}
			else if (strcmp(distance, "long") == 0) {
				fare = 300;
			}
			else {
				printf("\nInvalid input\n");
				return 1;
			}
			
			break;	
	default:
		printf("\nInvalid ride type\n");
		return 1;		
	}
	
	printf("\nYour ride type: %s", class_type);
	printf("\nYour fare is: %d", fare);
	
	return 0;
}





