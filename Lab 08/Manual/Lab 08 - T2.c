#include<stdio.h>
int main () {
	int i,j, zerocount, onecount;
	int beds[4][6], occupancy[4];
	
	for( i=0; i<4; i++) {
		printf("\nEnter bed status for Ward %d (0 = vacant, 1 = occupied)\n", i+1);
		zerocount = 0; onecount = 0;
		
		for(j=0; j<6; j++) {
			printf("  Bed %d: ", j+1);
			scanf("%d", &beds[i][j]);
			
			if (beds[i][j] == 0) {
				zerocount++;
			}
			else {
				onecount++;
			}
		}
		
	printf("Ward %d has %d vacant beds and %d occupied beds\n", i+1,zerocount,onecount);	
	occupancy[i] = (onecount*100)/6;
	printf("Ward %d has %d%% occupany \n", i+1,occupancy[i]);
	}
	
	
	for (i = 1; i < 5; i++) {
		if (occupancy[i] < 60) {
			printf("\nWard %d: Increase Admission Drive\n", i+1);
		}
	}
	return 0; 
}


