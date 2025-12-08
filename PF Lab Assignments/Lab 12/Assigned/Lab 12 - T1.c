#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, add, threshold;
    int *steps = NULL;
    int i = 0, total = 0, max = 0, countAbove = 0;
    FILE *fp;

    printf("Enter number of hours: ");
    scanf("%d", &n);

    steps = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++) {
        printf("Steps in hour %d: ", i+1);
        scanf("%d", (steps + i));
    }

    printf("Add more hours: ");
    scanf("%d", &add);

    if(add > 0) {
        steps = (int*)realloc(steps, (n + add) * sizeof(int));
        for(i = n; i < n + add; i++) {
            printf("Steps in hour %d: ", i+1);
            scanf("%d", (steps + i));
        }
        n += add;
    }

    max = *(steps);
    for(i = 0; i < n; i++) {
        total += *(steps + i);
        if(*(steps + i) > max)
            max = *(steps + i);
    }

    printf("Enter threshold: ");
    scanf("%d", &threshold);

    for(i = 0; i < n; i++)
        if(*(steps + i) > threshold)
            countAbove++;

    printf("Total Steps: %d\n", total);
    printf("Max Steps: %d\n", max);
    printf("Above Threshold: %d\n", countAbove);

    fp = fopen("fitness_tracker.txt", "w");
    fprintf(fp, "Total Steps: %d\nMax Steps: %d\nAbove Threshold: %d\n", total, max, countAbove);
    fclose(fp);

    printf("Results saved to fitness_tracker.txt\n");

    free(steps);
    return 0;
}







