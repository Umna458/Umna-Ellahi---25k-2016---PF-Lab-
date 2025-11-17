#include<stdio.h>
#include<stdlib.h>

int main() {
	char category[50], line[100];
	int amount;
	FILE *fexp;
	
	fexp = fopen("C:\\expenses.txt", "a");
	
	if (fexp == NULL) {
		printf("ERROR! Unable to opne file!\n");
		exit(1);
	}
		
	printf("Enter expense category: ");
	scanf(" %[^\n]", category);
	
	printf("Enter amount: ");
	scanf("%d", &amount);
	
	fprintf(fexp,"%s %d\n", category, amount);
	fclose(fexp);
	
	fexp = fopen("C:\\expenses.txt", "r");
	
	printf("\n=== EXPENSE TRACKER ===\n");
	while(fgets(line, sizeof(line), fexp)) {
		printf("%s", line);
	}
	
	fclose(fexp);
	return 0;
}
	
	
