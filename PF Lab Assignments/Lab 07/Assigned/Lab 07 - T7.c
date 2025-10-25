#include<stdio.h>
int main () {
	int vehicles[8] = {24,18,5,32,11,36,8,4};
	int i, alert=0;
	
	printf("---------------- Mileage Test ----------------\n\n");
	for(i = 0; i < 8; i++) {
		if (vehicles[i] >= 18) {
			printf("Vehcile %d\tCategory: Efficient\n", i+1);
		}
		else if (vehicles[i] >= 12 && vehicles[i] <= 17) {
			printf("Vehcile %d\tCategory: Average\n", i+1);
		}
		else if (vehicles[i] < 12) {
			printf("Vehicle %d\tCategory: Needs Maintenance\n", i+1);
			alert++;
		}
	}
	
	if (alert > 3) {
		printf("\nFleet Efficiency Alert!");
	}
	return 0;
}



