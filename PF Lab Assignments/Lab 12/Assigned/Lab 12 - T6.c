#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, add, i, max = 0, total = 0, maxGate = 0;
    int *attendance = NULL;
    FILE *fp;

    printf("Enter number of gates: ");
    scanf("%d", &n);

    attendance = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++) {
        printf("Gate %d count: ", i+1);
        scanf("%d", (attendance + i));
    }

    printf("Add more gates: ");
    scanf("%d", &add);

    if(add > 0) {
        attendance = (int*)realloc(attendance, (n + add) * sizeof(int));
        for(i = n; i < n + add; i++) {
            printf("Gate %d count: ", i+1);
            scanf("%d", (attendance + i));
        }
        n += add;
    }

    for(i = 0; i < n; i++) {
        total += *(attendance + i);
        if(*(attendance + i) > max) {
            max = *(attendance + i);
            maxGate = i + 1;
        }
    }

    fp = fopen("attendance.txt", "w");
    for(i = 0; i < n; i++)
        fprintf(fp, "Gate %d: %d\n", i+1, *(attendance + i));
    fprintf(fp, "\nTotal Attendees = %d\n", total);
    fprintf(fp, "Gate with Highest Attendance = Gate %d (%d)\n", maxGate, max);
    fclose(fp);

    printf("\n=========================================\n");
    printf("Event Attendance Summary:\n");
    printf("=========================================\n");
    for(i = 0; i < n; i++)
        printf("Gate %d: %d\n", i+1, *(attendance + i));
    printf("\nTotal Attendees = %d\n", total);
    printf("Gate with Highest Attendance = Gate %d (%d)\n", maxGate, max);
    printf("Attendance data saved to attendance.txt\n");

    free(attendance);
    return 0;
}



