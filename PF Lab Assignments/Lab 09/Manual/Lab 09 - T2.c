#include <stdio.h>

float HighTemp(float (*ptr)[4]);
int main() {
    float temp[5][4];
    float high[5];
    int i, j;

    printf("Enter temperature readings (F) for 5 patients (4 times each):\n");

    for (i = 0; i < 5; i++) {
        printf("\nPatient %d:\n", i + 1);
        for (j = 0; j < 4; j++) {
            printf("Reading %d: ", j + 1);
            scanf("%f", &temp[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        high[i] = HighTemp(&temp[i]);  // pointer to 2D array row
        printf("\nHighest temperature of Patient %d = %.2f F", i + 1, high[i]);

        if (high[i] > 101)
            printf("\t|\tALERT: Fever detected!");
    }

    printf("\n");

    return 0;
}

float HighTemp(float (*ptr)[4]) {
	int i;
    float high = *(*ptr);  
    for (i = 0; i < 4; i++) {
        if (*(*ptr + i) > high)
            high = *(*ptr + i);
    }
    return high;
}



