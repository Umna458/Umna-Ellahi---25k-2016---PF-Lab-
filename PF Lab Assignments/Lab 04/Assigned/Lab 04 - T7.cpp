#include <stdio.h>
#include <string.h>
int main () {
	int monthly_usage, fam_count, code; 
	int bill = 0, fine = 0, bonus =0;
	int saved_days;
	char category[50];
	
	
	printf("Enter your monthly water consumption (litres): ");
	scanf("%d", &monthly_usage);
	
	printf("Number of people in your family: ");
	scanf("%d", &fam_count);
	
	printf("\nEnter the category code that meets your criteria\n");
	printf("(1) Low Usage Household\n");
	printf("(2) Average Household\n");
	printf("(3) High Usage Household\n");
	printf("(4) Excessive Usage Household\n");
	printf("\nEnter category code (1-4):");
	scanf("%d", &code);
	
	printf("Enter number of days you saved water: ");
	scanf("%d", &saved_days);

	// Classifying Category
	if (code == 1) {
		strcpy(category, "Low Usage Household"); }	
	else if (code == 2) {
		strcpy(category, "Average Household"); }
	else if (code == 3) {
		strcpy(category, "High Usage Household"); }
	else if (code == 4) {
		strcpy(category, "Excessive Usage Household"); }
	else {
		printf("\nInvalid Category Code... Run Again!\n");
		return 1;
	}	
		
	// Classifying Bill	
	if (monthly_usage <= 3000) {
		bill = 500; }
	else {
		bill = 1000; }	
	
	// Classifying Fine
	if (monthly_usage > 3000 && monthly_usage <= 5000 && fam_count <= 6) {
		fine = 200; }
	else if (monthly_usage > 5000 && monthly_usage < 7000 && fam_count <= 6) {
		fine =  500; }
	else if (monthly_usage == 7000 and fam_count <= 6) {
		fine = 1000; }
	else {
		fine = 0; }
		
	// Classifying Bonus	
	if (monthly_usage < 2500) {
		if (saved_days > 10) {
			bonus =  300; }
	else {
		bonus = 0; }
	}
	
	printf("\nCategory: %s\n", category);
    printf("Bill: %d\n", bill);
    printf("Fine: %d\n", fine);
    printf("Bonus: %d\n", bonus);
		
}		
		
		
	
