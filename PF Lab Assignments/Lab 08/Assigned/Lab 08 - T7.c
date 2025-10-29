#include<stdio.h>
int main () {
	int encrypted[3][3];
	int data[3][3];
	int key[3][3];
	int i, j;
	
	printf("---- Input for Data ----\n");
	for (i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("Enter input for [%d][%d]: ", i+1, j+1);
			scanf("%d", &data[i][j]);		
		}
	}
	
	printf("\n---- Input for Key ----\n");
	for (i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("Enter input for [%d][%d]: ", i+1, j+1);
			scanf("%d", &key[i][j]);		
		}
	}
	
	printf("\n=== Data Matrix ===\n");
	for (i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("%d\t", data[i][j]);		
		}
		printf("\n");
	}
	
	printf("\n=== Key Matrix ===\n");
	for (i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("%d\t", key[i][j]);		
		}
		printf("\n");
	}
	
	printf("\n=== Encrypted Matrix ===\n");
	for (i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			encrypted[i][j] = (data[i][j] * key[i][j] +(i+j));
			printf("%d\t", encrypted[i][j]);
		}
		printf("\n");
	}
	
	int highest = 0; int maxrow; int maxcol;
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++){
			if (encrypted[i][j] > highest) {
				highest = encrypted[i][j];
				maxrow = i;
				maxcol = j;
			}
		}
	}
	
	printf("\n\nMaximum Encrypted Value [%d][%d]: %d", maxrow+1, maxcol+1, highest);
	return 0;
	
}


