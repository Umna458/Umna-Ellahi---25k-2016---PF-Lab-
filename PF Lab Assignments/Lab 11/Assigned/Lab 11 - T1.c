#include <stdio.h>
#include <math.h>
struct Building {
    int id;
    double initial_height;
    double growth_rate;
};

// Recursive function to calculate height at day n
double calculate_height(struct Building *b, int n) {
    if (n == 0) {
        return b->initial_height;
    }

    double prev_height = calculate_height(b, n - 1);
    double increase = floor(prev_height * b->growth_rate);

    return prev_height + increase;
}

int main() {
    struct Building b1;
    int day;

    printf("Enter Building ID: ");
    scanf("%d", &b1.id);

    printf("Enter Initial Height of Building: ");
    scanf("%lf", &b1.initial_height);

    printf("Enter Growth Rate (e.g., 0.10 for 10%%): ");
    scanf("%lf", &b1.growth_rate);

    printf("Enter number of days: ");
    scanf("%d", &day);

    double height_n = calculate_height(&b1, day);

    b1.initial_height = height_n;

    printf("\n=== Building Height Simulation ===\n");
    printf("Building ID: %d\n", b1.id);
    printf("Height at Day %d: %.2lf units\n", day, b1.initial_height);

    return 0;
}



