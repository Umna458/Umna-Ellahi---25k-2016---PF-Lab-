#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, add, i = 0, count = 0;
    float *t = NULL, max, min, alert;
    FILE *fp;

    printf("Enter readings count: ");
    scanf("%d", &n);

    t = (float*)malloc(n * sizeof(float));

    for(i = 0; i < n; i++)
        scanf("%f", (t + i));

    printf("Add more: ");
    scanf("%d", &add);

    if(add > 0) {
        t = (float*)realloc(t, (n + add) * sizeof(float));
        for(i = n; i < n+add; i++)
            scanf("%f", (t + i));
        n += add;
    }

    max = min = *t;

    for(i = 0; i < n; i++) {
        if(*(t+i) > max) max = *(t+i);
        if(*(t+i) < min) min = *(t+i);
    }

    printf("Alert threshold: ");
    scanf("%f", &alert);

    for(i = 0; i < n; i++)
        if(*(t+i) > alert)
            count++;

    fp = fopen("temperature_summary.txt", "w");
    fprintf(fp, "Max=%f\nMin=%f\nAbove Alert=%d\n", max, min, count);
    fclose(fp);

    free(t);
    return 0;
}




