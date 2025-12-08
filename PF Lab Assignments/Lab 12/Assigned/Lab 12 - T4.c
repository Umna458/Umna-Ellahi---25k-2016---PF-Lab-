#include <stdio.h>
#include <stdlib.h>

struct Log {
    char title[50];
    char member[20];
    int time;
    int days;
    int due;
};

int main() {
    int n, add, i = 0;
    struct Log *L = NULL;
    FILE *fp;

    printf("Enter number of logs: ");
    scanf("%d", &n);

    L = (struct Log*)malloc(n * sizeof(struct Log));

    for(i = 0; i < n; i++) {
        printf("\n--- Log %d ---\n", i+1);
        printf("Book Title: ");
        scanf("%s", L[i].title);
        printf("Member ID: ");
        scanf("%s", L[i].member);
        printf("Checkout Time: ");
        scanf("%d", &L[i].time);
        printf("Return Due Days: ");
        scanf("%d", &L[i].days);
        L[i].due = L[i].time + L[i].days;
    }

    printf("\nAdd more logs: ");
    scanf("%d", &add);

    if(add > 0) {
        L = (struct Log*)realloc(L, (n + add) * sizeof(struct Log));
        for(i = n; i < n+add; i++) {
            printf("\n--- Log %d ---\n", i+1);
            printf("Book Title: ");
            scanf("%s", L[i].title);
            printf("Member ID: ");
            scanf("%s", L[i].member);
            printf("Checkout Time: ");
            scanf("%d", &L[i].time);
            printf("Return Due Days: ");
            scanf("%d", &L[i].days);
            L[i].due = L[i].time + L[i].days;
        }
        n += add;
    }

    fp = fopen("library_log.csv", "w");
    fprintf(fp, "Title,Member,Checkout,Days,DueDate\n");
    for(i = 0; i < n; i++)
        fprintf(fp, "%s,%s,%d,%d,%d\n", L[i].title, L[i].member, L[i].time, L[i].days, L[i].due);
    fclose(fp);

    printf("\n=========================================\n");
    printf("Library logs saved successfully to library_log.csv\n");
    printf("Final Checkout Summary:\n");
    printf("=========================================\n");
    printf("Title\tMember\tCheckout\tDays\tDueDate\n");
    for(i = 0; i < n; i++)
        printf("%s\t%s\t%d\t\t%d\t%d\n", L[i].title, L[i].member, L[i].time, L[i].days, L[i].due);

    free(L);
    return 0;
}




