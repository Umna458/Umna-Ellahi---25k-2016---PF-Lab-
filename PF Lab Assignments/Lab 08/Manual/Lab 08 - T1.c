#include<stdio.h>
int main () {
	int i,j, temp, sum; //i - city , j - days
	int highest_city = 0, highest = 0; 
	int result[5][7], avg[5];
	
	for (i = 0; i < 5; i++) {
		sum = 0;
		for(j = 0; j < 7; j++) {
			printf("Enter temperature (in celsius) for City %d, Day %d: ", i+1, j+1);
			scanf("%d", &temp);
			result[i][j] = temp;
			sum += temp;
		}
	avg[i] = sum/7;
	}
	
	for(i = 0; i < 5; i++) {
	printf("City %d Average: %d\n", i+1, avg[i]);
	}
	
	highest = avg[0];
	for (i = 1; i < 5; i++) {
		if (avg[i] > highest) {
			highest = avg[i];
			highest_city = i;
		}
	}
	
	printf("Highest Weekly Average Tempaerature is %d of city %d", highest, highest_city+1);
	return 0;
}





