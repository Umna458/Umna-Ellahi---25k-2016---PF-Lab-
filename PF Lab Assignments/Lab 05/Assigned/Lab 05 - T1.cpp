#include<stdio.h>
int main() {
	int age, acc_bal;
	
	printf("Enter your age: ");
	scanf("%d", &age);
	
	printf("Enter your account balance: ");
	scanf("%d", &acc_bal);
	
	if (age <21){
		printf("Not eligible for ride (underage)");	
	}
	else if (acc_bal <200) {
		printf("Not eligible (insufficient balance)");
	}
	else{
		printf("Eligible for ride");
	}
	return 0;
}



