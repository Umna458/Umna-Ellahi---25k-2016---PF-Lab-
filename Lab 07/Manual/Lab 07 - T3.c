#include <stdio.h>

int main() {
    int weight[8];
    int i, flagged = 0;
    int fine = 0, total = 0;

    for(i = 0; i < 8; i++) {
        printf("Enter baggage weight of passenger %d: ", i + 1);
        scanf("%d", &weight[i]);
    }

    for(i = 0; i < 8; i++) {
        if(weight[i] <= 20) {
            fine = 0;
            printf("Passenger %d: %d kg - Free\n", i+1, weight[i]);
        }
        else if(weight[i] <= 30) {
            fine = 500;
            printf("Passenger %d: %d kg - Fine Rs.500\n", i+1, weight[i]);
        }
        else {
            fine = 1000;
            flagged++;
            printf("Passenger %d: %d kg - Fine Rs.1000 (Flagged)\n", i+1, weight[i]);
        }
        total += fine;
    }

    printf("\nTotal fine collected: Rs. %d\n", total);
    printf("Flagged baggage count: %d\n", flagged);

    return 0;
}



