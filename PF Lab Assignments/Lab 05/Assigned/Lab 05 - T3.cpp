#include <stdio.h>

double simpleSqrt(double n) {
    double i = 0;
    while (i * i <= n) {
        i = i + 0.0001;  // small step to get close to the square root
    }
    return i;
}

int main() {
    int rides;
    double surge_multiplier;

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

    printf("Your surge multiplier is: %.2lf", surge_multiplier);
    return 0;
}





