#include<stdio.h>
int main () {
	int code;
	
	printf("Enter incident severity code (1-4): ");
	scanf("%d", &code);
	
	switch(code) {
		case 1: 
			printf("Low Unusual login time\n");
			break;
		case 2:
			printf("Medium (Suspicious failed attempts)\n");
			break;
		case 3:
			printf("High (Multiple accounts targeted)\n");
			break;	
		case 4:
			printf("Critical (Brute-force/Dos attack detected)\n");
			break;	
	default:
		printf("Invalid Code");		
	}
	return 0;
}
