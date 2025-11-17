#include <stdio.h>


void calculate_average(int numVehicles, int numDays, float mileage[][7], float avg[]);
void showAverageReport(int numVehicles, float avg[]);
void showCategoryReport(int numVehicles, float avg[]);

int main() {
    int numVehicles = 5;
    int numDays = 7;
    float mileage[5][7]; 
    float avg[5];
    int vehicleIndex, dayIndex;
    int reportChoice;

    printf("Enter mileage for 5 vehicles for 7 days (km/l):\n");
    for (vehicleIndex = 0; vehicleIndex < numVehicles; ++vehicleIndex) {
        printf("Vehicle %d:\n", vehicleIndex + 1);
        for (dayIndex = 0; dayIndex < numDays; ++dayIndex) {
            printf("  Day %d: ", dayIndex + 1);
            scanf("%f", &mileage[vehicleIndex][dayIndex]);
        }
    }

 
    calculate_average(numVehicles, numDays, mileage, avg);

    
    void (*displayReport)(int, float*);
    printf("\nChoose report format:\n1. Average Only\n2. Average + Category\nYour choice: ");
    scanf("%d", &reportChoice);

    if (reportChoice == 1)
        displayReport = showAverageReport;
    else
        displayReport = showCategoryReport;

    displayReport(numVehicles, avg);

    return 0;
}


void calculate_average(int numVehicles, int numDays, float mileage[][7], float avg[]) {
	int i,j;
	
    for (i = 0; i < numVehicles; ++i) {
        float sum = 0.0;
        for (j = 0; j < numDays; ++j) {
            sum += mileage[i][j];
        }
        avg[i] = sum / numDays;
    }
}


void showAverageReport(int numVehicles, float avg[]) {
	int i;
	
    printf("\nVehicle averages (compact report):\n");
    for (i = 0; i < numVehicles; ++i) {
        printf("Vehicle %d: %.2f km/l  ", i + 1, avg[i]);
    }
    printf("\n");
}


void showCategoryReport(int numVehicles, float avg[]) {
	int i;
	
    printf("\nVehicle detailed report:\n");
    for (i = 0; i < numVehicles; ++i) {
        printf("Vehicle %d -> Avg: %.2f km/l -> Category: ", i + 1, avg[i]);
        if (avg[i] >= 18.0)
            printf("Efficient\n");
        else if (avg[i] >= 12.0)
            printf("Moderate\n");
        else
            printf("Poor\n");
    }
}


