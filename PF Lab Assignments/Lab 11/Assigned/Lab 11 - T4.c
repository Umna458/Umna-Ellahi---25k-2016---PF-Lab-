#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct WeatherData {
    char cityName[50];
    float baseTemp;
    float coolingFactor;
};

float simulateTemp(struct WeatherData *w, int n) {
    if (n == 0) {
        return w->baseTemp;  
    }
    float initialTemp = simulateTemp(w, n - 1);
    float randomVariation = ((rand() % 400) / 100.0) - 2.0;
    float newTemp = initialTemp + randomVariation - w->coolingFactor;
    return newTemp;
}

int main() {
    struct WeatherData w1;
    int days;

    srand(time(0));

    printf("Enter City Name: ");
    scanf("%s", w1.cityName);

    printf("Enter Base Temperature: ");
    scanf("%f", &w1.baseTemp);

    printf("Enter Daily Cooling Factor: ");
    scanf("%f", &w1.coolingFactor);

    printf("Enter Number of Days to Simulate: ");
    scanf("%d", &days);

    float predictedTemp = simulateTemp(&w1, days);

    printf("\n=== Weather Forecast Simulation ===\n");
    printf("City: %s\n", w1.cityName);
    printf("Base Temperature: %.2f\n", w1.baseTemp);
    printf("Cooling Factor: %.2f/day\n", w1.coolingFactor);
    printf("Days Simulated: %d\n", days);
    printf("Predicted Temperature After %d Days: %.2f\n", days, predictedTemp);

    return 0;
}




