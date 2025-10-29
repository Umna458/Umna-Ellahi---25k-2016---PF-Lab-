#include<stdio.h>
int main () {
	int temp[3][3][3] = {0}, layer[3] = {0}, avg[3] = {0};
	int x, y, z;
	
	printf("---- Input for Temperature ----\n");
	for (x=0; x<3; x++) {
		printf("\nLayer %d\n", x+1);
		for(y=0; y<3; y++) {
			for(z=0; z<3; z++) {
				printf("  Enter temp for Cell [%d][%d]: ", y+1, z+1);
				scanf("%d", &temp[x][y][z]);
				layer[x] += temp[x][y][z];
			}
		}
		avg[x] = layer[x] / 9;
	}
	
	
	printf("\n=== Temperature Grid ===\n");
	for (y=0; y<3; y++) {
		for(x=0; x<3; x++) {
			for(z=0; z<3; z++) {
				printf("%d  ", temp[x][y][z]);
			}
			printf("\t");
		}
		printf("\n");
	}
	
	int hottest = avg[0], hotlayer;
	for (x=0; x<3; x++) {
		printf("\nAverage Temperature of Layer %d is %d.", x+1, avg[x]);
		if (avg[x] > hottest) {
			hottest = avg[x];
			hotlayer = x;
		}
	}
	printf("\nHottest Layer is %d with Temrature %d Celsius.", hotlayer+1, hottest);
	
	int max = temp[0][0][0], page=0, row=0, col;
	for (x=0; x<3; x++) {
		for(y=0; y<3; y++) {
			for(z=0; z<3; z++) {
				if (temp[x][y][z] > max) {
					max = temp[x][y][z];
					page = x;
					row = y;
					col = z;
				}
			}
		}
	}
	
	printf("\n\nMaximum Temperature Point is Cell [%d][%d][%d] with Temperature %d Celsius.", page+1, row+1, col+1, max);
	return 0;
	
}







