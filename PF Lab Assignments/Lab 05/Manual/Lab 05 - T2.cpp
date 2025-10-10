#include <stdio.h>
int main() {
	int email, action;
	
	// Input for email
	printf("Choose phishing email type\n");
	printf("(1) Fake Login Page\n");
	printf("(2) Malicious Link\n");
	printf("(3) Urgent Money Request\n");
	scanf("%d", &email);
	
	// Input for user action
	printf("Choose user action\n");
	printf("(1) Clicked\n");
	printf("(2) Reported\n");
	printf("(3) Ignored\n");
	scanf("%d", &action);
	
	
	switch(email) {
		case 1:
		case 2:
		case 3: 	
			switch(action)
			{
				case 1:
					printf("High Risk\n");
					break;
				case 2:
					printf("Low Risk\n");
					break;	
				case 3:
					printf("Medium Risk\n");
					break;
				default:
					printf("Invalid input\n");		
			}
			break;
		default:
			printf("Invalid email type\n");

	}
	return 0;
}


