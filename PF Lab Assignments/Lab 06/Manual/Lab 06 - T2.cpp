#include <stdio.h>
int main () {
	int years = 0;
	float car = 30000.0;
	
	while (car >=  15000) {
		car = car - (car * 0.10);
		years++;
		printf("Value after year %d: %.2f\n", years, car);
	}
	printf("It took %d years to depreciate car below $15000\n", years);
	return 0;
}




