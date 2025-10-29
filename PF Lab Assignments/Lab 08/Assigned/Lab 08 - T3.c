#include<stdio.h>
int main () {
	int sales[4][5];
	int price, totalsales[5] = {0}, totalsalesman[4] = {0}, high_salesman = 0;
	int i, j, highest = 0;
	float bonus;
	
	for (i=0; i<4; i++) {
		printf("\nSalesman %d:\n", i+1);
		for(j=0; j<5; j++) {
			printf("\tProduct %d: Rs.", j+1);
			scanf("%d", &sales[i][j]);
			
			totalsales[j] += sales[i][j]; // total sales per product
			totalsalesman[i] += sales[i][j]; // total sales per salesman
			
			if(sales[i][j] > highest) {
				highest = sales[i][j]; // checking highest sales
				high_salesman = i; // highest sales made by salesman
			}
		}
	}
	
	printf("\n=== Sales Per Salesman ===\n");
	for(i=0; i<4; i++){
		printf("Salesman %d: Rs.%d", i+1, totalsalesman[i]);
		if (totalsalesman[i] > 10000) {
			bonus = totalsalesman[i] *0.10;
			printf("  (Bonus: Rs:%.2f)", bonus);
		}
		printf("\n");
	}
	
	printf("\n=== Total Sales Per Product ===\n");
	for (j=0; j<5; j++) {
		printf("Product %d: Rs.%d\n", j+1, totalsales[j]);
	}
	
	printf("\nSalesman %d sold the most expensive product worth Rs.%d\n", high_salesman+1, highest);
	return 0;
	
}




