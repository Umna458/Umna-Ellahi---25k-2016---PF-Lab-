#include<stdio.h>
int main () {
	int seats[10][4] = {0};
	int i, j, row, col, fullrows = 0;
	char choice;
	
	do {
		printf("Enter row number (1-10): ");
		scanf("%d", &row);
		printf("Enter seat number (1-4): ");
		scanf("%d", &col);
		
		if (row < 1 || row > 10 || col < 1 || col > 4) {
			printf("Invalid seat!\n");
		}
		else if (seats[row - 1][col - 1] == 1) {
			printf("Seat not avaliable.\n");
		}
		else {
			seats[row - 1][col - 1] = 1;
			printf("Seat number %d-%d is reserved successfully!\n", row, col);
		}
		
		printf("\nWould you like to book another seat? (Y for yes, N for no): ");
		scanf(" %c", &choice);
	} while (choice == 'Y' || choice == 'y');
	
	printf("\n ==== Seat Map ====\n");
	for ( i = 0; i < 10; i++) {
		printf("Row %d:\t", i+1);
		for ( j = 0; j < 4; j++) {
			printf("%d", seats[i][j]);
		}
		printf("\n");
	}
	
	for ( i = 0; i < 10; i++){
		int sum = 0;
		for ( j = 0; j < 4; j++) {
				sum += seats[i][j];
		}
			if (sum == 4) {
				fullrows++;
			}
	}
	
	
	printf("\nNumber of Completely Booked Rows are: %d", fullrows);
	return 0;
}




