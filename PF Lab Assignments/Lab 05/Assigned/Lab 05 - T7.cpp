#include <stdio.h>
#include <string.h>

// Simple square root function (no math.h)
double simpleSqrt(double n) {
    double i = 0;
    while (i * i <= n) {
        i = i + 0.0001;  // small step to get close to the square root
    }
    return i;
}

int main() {
    int ride_type, fare = 0, rides, driver_distance, age, acc_bal, rating, loyalty_points;
    char passenger_message[100], driver_assigned[100], passenger_distance[50], class_type[50];
    double surge_multiplier;
    float discount, finalfare;

    // Code for PASSENGER ELIGIBILITY
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your account balance: ");
    scanf("%d", &acc_bal);

    if (age < 21 && acc_bal < 200) {
        strcpy(passenger_message, "Passenger Eligibility: Not eligible for ride (underage & insufficient balance)");
        printf("\n-------RIDE SUMMARY------\n");
        printf("%s\n", passenger_message);
        return 1;
    } else {
        strcpy(passenger_message, "Passenger Eligibility: Eligible for ride");
    }

    // Code for DRIVER ASSIGNMENT
    printf("What is the driver rating? (1-5): ");
    scanf("%d", &rating);

    printf("What is the driver distance from passenger?: ");
    scanf("%d", &driver_distance);

    if (rating >= 4 && driver_distance <= 5) {
        strcpy(driver_assigned, "Driver Assigned: Top driver nearby");
    } else if (rating >= 3 && driver_distance <= 10) {
        strcpy(driver_assigned, "Driver Assigned: Average driver assigned");
    } else {
        strcpy(driver_assigned, "Driver Assigned: No suitable driver available");
        printf("\n-------RIDE SUMMARY------\n");
        printf("%s\n", driver_assigned);
        return 1;
    }

    // Code for RIDE TYPE
    printf("\nChoose your ride type\n");
    printf("(1) Economy\n");
    printf("(2) Business\n");
    printf("(3) Luxury\n");
    printf("Enter your choice: ");
    scanf("%d", &ride_type);

    printf("\nEnter your distance to be travelled (short/long): ");
    scanf(" %s", passenger_distance);

    switch (ride_type) {
        case 1:
            strcpy(class_type, "Class Type: Economy ride");
            if (strcmp(passenger_distance, "short") == 0) {
                fare = 100;
            } else if (strcmp(passenger_distance, "long") == 0) {
                fare = 300;
            } else {
                printf("\nInvalid input\n");
                return 1;
            }
            break;

        case 2:
            strcpy(class_type, "Class Type: Business ride");
            if (strcmp(passenger_distance, "short") == 0) {
                fare = 200;
            } else if (strcmp(passenger_distance, "long") == 0) {
                fare = 500;
            } else {
                printf("\nInvalid input\n");
                return 1;
            }
            break;

        case 3:
            strcpy(class_type, "Class Type: Luxury ride");
            if (strcmp(passenger_distance, "short") == 0) {
                fare = 400;
            } else if (strcmp(passenger_distance, "long") == 0) {
                fare = 800;
            } else {
                printf("\nInvalid input\n");
                return 1;
            }
            break;

        default:
            printf("\nInvalid ride type\n");
            return 1;
    }

    // Code for SURGE MULTIPLIER (without math.h)
    printf("Enter the number of rides requested: ");
    scanf("%d", &rides);

    if (rides <= 0) {
        printf("\nInvalid input\n");
        return 1;
    }

    surge_multiplier = simpleSqrt(rides) / 2.0;

    if (surge_multiplier > 3.0) {
        surge_multiplier = 3.0;
    }

    // Code for DISCOUNTS
    printf("Enter your loyalty points: ");
    scanf("%d", &loyalty_points);

    (loyalty_points > 1000) ? (discount = 0.20) : (discount = 0.05);
    finalfare = fare * surge_multiplier * (1 - discount);

    // RIDE SUMMARY
    printf("\n-------RIDE SUMMARY------\n");
    printf("%s\n", passenger_message);
    printf("%s\n", driver_assigned);
    printf("%s\n", class_type);
    printf("\nYour Final Fare is: %.2f\n", finalfare);

    return 0;
}

