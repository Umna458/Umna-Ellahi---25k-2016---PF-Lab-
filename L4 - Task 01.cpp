#include <stdio.h>

int main() {
	// Validation of Student ID
	//Inputs
	int stID, registeredID;
	registeredID = 2016;
	
	printf("Enter the LAST 4 digits of your Student ID: ");
	scanf("%d", &stID);
	
	if (stID == registeredID) {
		printf("Valid User: Proceed to login\n");		
	}
	else {
		printf("Unknown User: Access Denied");
	}
	
	return 0;
}


