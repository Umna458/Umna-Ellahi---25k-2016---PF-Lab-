#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, add, i = 0, max = 0, total = 0;
    int *d = NULL, rate = 500;
    FILE *fp;

    printf("Enter number of rentals: ");
    scanf("%d", &n);

    d = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++) {
        printf("Duration for rental %d: ", i+1);
        scanf("%d", (d+i));
    }

    printf("Add more rentals: ");
    scanf("%d", &add);

    if(add > 0) {
        d = (int*)realloc(d, (n+add) * sizeof(int));
        for(i = n; i < n+add; i++) {
            printf("Duration for rental %d: ", i+1);
            scanf("%d", (d+i));
        }
        n += add;
    }

    for(i = 0; i < n; i++) {
        total += *(d+i);
        if(*(d+i) > max) max = *(d+i);
    }

    fp = fopen("Rental_Invoices.txt", "w");
    for(i = 0; i < n; i++)
        fprintf(fp, "Customer %d: Duration=%d Cost=%d\n", i+1, *(d+i), *(d+i)*rate);
    fprintf(fp, "Total=%d Max=%d\n", total, max);
    fclose(fp);

    printf("\n=========================================\n");
    printf("Rental Invoices Generated:\n");
    printf("=========================================\n");
    for(i = 0; i < n; i++)
        printf("Customer %d: Duration=%d Cost=%d\n", i+1, *(d+i), *(d+i)*rate);
    printf("Total Rental Hours = %d\n", total);
    printf("Maximum Rental Duration = %d\n", max);
    printf("Invoices saved to Rental_Invoices.txt\n");

    free(d);
    return 0;
}




