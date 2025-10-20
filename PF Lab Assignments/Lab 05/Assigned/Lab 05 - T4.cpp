#include<stdio.h>
#include<string.h>

double simpleSqrt(double n) {
    double i = 0;
    while (i * i <= n) {
        i = i + 0.0001;  // small step to get close to the square root
    }
    return i;
}

int main() {
	int rides;
	double surge_multiplier,total_fare,distance,fare=0.0;
	char ride_type[10];
	
    printf("Enter the number of rides requested: ");
    scanf("%d", &rides);

    if (rides < 0) {
        printf("Invalid input\n");
        printf("Try Again!\n");
        return 0;
    }

    surge_multiplier = simpleSqrt(rides) / 2.0;

    if (surge_multiplier > 3.0) {
        surge_multiplier = 3.0;
    }

		
	//Finding fare/distance
	printf("Enter your distance travelled: ");
	scanf("%lf", &distance);
	
	printf("Enter your ride type: \n 1.Economy\n 2.Business\n 3.Luxury\n");
	printf("Enter your choice: ");
	scanf("%s", ride_type);
	
	if(strcmp(ride_type, "Economy") == 0){
		fare = 50;
	}
	else if(strcmp(ride_type, "Business") == 0) {
		fare = 100;
	}
	else if(strcmp(ride_type, "Luxury") == 0) {
		fare = 200;
	}
	else {
		printf("Invalid ride type\n");
		return 1;
	}
	
	//Calculating Total Fare
	total_fare = distance*fare*surge_multiplier;
	
	printf("\nTotal Fare: %.2f\n", total_fare);
	return 0;
	
}





