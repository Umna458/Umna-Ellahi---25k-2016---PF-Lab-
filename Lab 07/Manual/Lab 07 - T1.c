#include <stdio.h>

int main() {
    int hours[10], i, overstaying_count = 0;
    int fee, total = 0;

    for(i = 0; i < 10; i++) {
        printf("Enter parking hours: ", i + 1);
        scanf("%d", &hours[i]);
    }

    for(i = 0; i < 10; i++) {
        if(hours[i] <= 2)
            fee = hours[i] * 50;
        else if(hours[i] <= 5)
            fee = hours[i] * 40;
        else
            fee = hours[i] * 30;

        if(hours[i] > 8) {
            printf("Car %d: Rs.%d - Overstay Warning!\n", i + 1, fee);
            overstaying_count++;
        } else
            printf("Car %d: Rs.%d\n", i + 1, fee);

        total += fee;
 	}

    printf("\nTotal revenue: Rs.%d\n", total);
    printf("Overstaying cars: %d\n", overstaying_count);

    return 0;
}



