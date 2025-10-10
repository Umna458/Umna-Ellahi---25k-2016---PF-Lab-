#include <stdio.h>
int main() {
	int  days = 0;
	float meters = 500.0;
	
	while (meters < 2000) {
		meters = meters + (meters*0.05);
		days++;
	}
	printf("It took the jogger %d days to run atleast 2000m\n", days);
	printf("Jogger ran %.2f meters on the final day\n", meters);
	return 0;
}




