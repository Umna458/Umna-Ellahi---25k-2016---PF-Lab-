#include<stdio.h>
int main () {
	int ward[] = {12, 3, 8, 21, 4, 11, 9};
	int patients = 0, total, i;
	
	for(i = 0; i < 7; i++) {
		if (ward[i] > 10) {
			printf("Ward %d: Overcrowded\t\t  Review: Required\n", i+1);
			patients += ward[i];
		}
		else if (ward[i] >= 6 && ward[i] <= 10) {
			printf("Ward %d: Stable\t\t\t  Review: Not Required\n", i+1);
			patients += ward[i];
		}
		else if (ward[i] < 6) {
			printf("Ward %d: Underutilized\t\t  Review: Required\n", i+1);
			patients += ward[i];
		}
		else
		printf("Invalid Input");
	}
	
	printf("\nTotal number of patients are: %d", patients);
	return 0;
}


