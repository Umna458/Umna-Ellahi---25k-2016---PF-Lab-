#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Seat {
    char name[50];
    char roll[20];
    int seat;
};

int validate(char *s, int idx) {
    if (s[idx] == '\0') return 1;
    if (!isalnum(s[idx])) return 0;
    return validate(s, idx + 1);
}

int main() {
    int n, add, i;
    struct Seat *list = NULL;
    FILE *fp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    list = (struct Seat*)malloc(n * sizeof(struct Seat));

    for (i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Name: ");
        scanf("%s", list[i].name);

    again_roll1:
        printf("Roll: ");
        scanf("%s", list[i].roll);
        if (!validate(list[i].roll, 0)) {
            printf("Invalid! Only alphanumeric allowed.\n");
            goto again_roll1;
        }

        printf("Seat#: ");
        scanf("%d", &list[i].seat);
    }

    printf("\nAdd more students: ");
    scanf("%d", &add);

    if (add > 0) {
        list = (struct Seat*)realloc(list, (n + add) * sizeof(struct Seat));

        for (i = n; i < n + add; i++) {
            printf("\n--- New Student %d ---\n", i + 1);

            printf("Name: ");
            scanf("%s", list[i].name);

        again_roll2:
            printf("Roll: ");
            scanf("%s", list[i].roll);
            if (!validate(list[i].roll, 0)) {
                printf("Invalid! Only alphanumeric allowed.\n");
                goto again_roll2;
            }

            printf("Seat#: ");
            scanf("%d", &list[i].seat);
        }

        n += add;
    }

    fp = fopen("seating.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(fp, "%s %s %d\n", list[i].name, list[i].roll, list[i].seat);
    fclose(fp);

    printf("\n=========================================\n");
    printf("DATA SAVED SUCCESSFULLY TO seating.txt\n");
    printf("FINAL SEATING LIST:\n");
    printf("=========================================\n");

    for (i = 0; i < n; i++)
        printf("%s\t%s\t%d\n", list[i].name, list[i].roll, list[i].seat);

    free(list);
    return 0;
}





