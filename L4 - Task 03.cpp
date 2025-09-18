#include <stdio.h>

int main() {
	int code;
	
	printf("Enter incident severity code (1-4): ");
	scanf("%d", &code);
	
	switch(code) {
		case 1:
			printf("Low (Unusual login time\n)");
			break;
		case 2:
			printf("Medium (Suspicious failed attempts\n");
			break;
		case 3:
			printf("High (Multiple accounts targeted)\n");
			break;
		case 4:
			printf("Critical (Brute-force/DDoS attack detected)");
			break;
	deafult:
		printf("Invalid Code: Enter a number between 1 and 4");
	}
	return 0;
			

}

