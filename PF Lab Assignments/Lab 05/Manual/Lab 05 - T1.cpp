#include <stdio.h>
int main () {
	int attempts, t_int;
	
	printf("Enter number of login attempts: "); // number of login attempts
	scanf("%d", &attempts);
	
	printf("Enter time interval of attempts: "); // time interval in minutes
	scanf("%d", &t_int);
	
	if (attempts > 5 && t_int < 10) {
		printf("Brute-Force Attack");}
	else if (attempts > 3 && t_int < 30) {
		printf("Suspicious Activity");	}
	else {
		printf("Normal Login Behavior"); }
	return 0;
}
	
	
	
	
