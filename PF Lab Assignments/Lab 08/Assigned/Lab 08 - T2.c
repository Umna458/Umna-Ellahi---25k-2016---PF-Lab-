#include<stdio.h>
int main () {
	int sudoku[3][3] = {{8, 0, 0},{0, 0, 7},{0, 1, 0} }; 
	int i,j,x,y, valid = 1, duplicate = 0;
	 
	printf("Initial Sudoku Grid\n");
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("%d\t", sudoku[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter number to fill grid between (1-9) strictly - NO REPEATS\n");
	
	for (i=0; i<3; i++){
		for(j=0; j<3; j++) {
			if (sudoku[i][j] == 0) {
				printf("Enter value for cell [%d][%d]: ", i+1, j+1);			
				scanf("%d", &sudoku[i][j]);
			}
			
			if (sudoku[i][j] < 0 || sudoku[i][j] > 9) {
				valid = 0;
			}
		}
	}
	
	printf("\nYour Sudoku Grid\n");
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("%d\t", sudoku[i][j]);
		}
		printf("\n");
	}

	// i and j - the current index of the cell
	// x and y - the index of the cell being compared against
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			if (sudoku[i][j] != 0) {
				for (x=0; x<3; x++) {
					for (y=0; y<3; y++) {
						if((i != x || j != y) && sudoku[i][j] == sudoku[x][y]) { // row and col ndex not same && value not same
							valid = 0;
							duplicate = 1;
						}
					}
				}
			}
		}
	}
	
	if (duplicate) {
		printf("\nDuplicate numbers found!\n");
	}
	else {
		printf("No duplicates found\n");
	}
	
	if (valid) {
		printf("Valid Grid\n");
	}
	else {
		printf("Invalid Grid\n");
	}
	
	return 0;
}

