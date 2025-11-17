#include<stdio.h>
#include<stdlib.h>

int main () {
	int quantity;
	float price;
	char p_name[50];
	FILE *fproducts;
	
	fproducts = fopen("C:\\products.txt", "a");
	
	if (fproducts == NULL) {
		printf("ERROR! Unable to open file!\n");
		exit(1);
	}
	
	printf("=== DATA LOGGER ===\n");
	
	printf("Enter product name: ");
	scanf("%s", p_name);
	
	printf("Enter product price: ");
	scanf("%f", &price);

	printf("Enter quantity: ");
	scanf("%d", &quantity);
	
	fprintf(fproducts, "Product: %s, Price: %.2f, Quantity: %d\n", p_name, price, quantity);

	printf("Data stored successfully.\n");
	printf("Exiting program...\n");
	
	fclose(fproducts);
	
	return 0;

	
}


