#include<stdio.h>
int main () {
	int data[10] = {200,300,700,400,1200,100,50,230,340,440};
	int totalbill[10];
	int flag = 0, revenue = 0;
	int unitcost, i; 
	
	for( i = 0; i < 10; i++) {
		if (data[i] <= 200) {
			unitcost = 15;
		}
		else if (data[i] > 200 && data[i] <= 500) {
			unitcost = 20;
		}		
		else if (data[i] > 500) {
			unitcost = 25;
		}
		
		totalbill[i] = data[i] * unitcost;
	    revenue += totalbill[i];
	    
		if (data[i] > 700) {
			flag++;
			printf("House %d:\tUnits: %d\tBill: Rs.%d\tFlag: High Consumption\n", i+1, data[i], totalbill[i]);
	    }
	   	else {
	    	printf("House %d:\tUnits: %d\tBill: Rs.%d\tFlag: Normal\n", i+1, data[i], totalbill[i]);
		}

	}	
	printf("\nTotal Revenue: %d", revenue);
	printf("\nNumber of Houses Flagged are: %d", flag);
	return 0;
}



