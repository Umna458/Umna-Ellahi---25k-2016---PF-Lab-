#include <stdio.h>
#include <stdlib.h>

struct User {
    char name[50];
    int daysRecorded;
    float *units; 
};

typedef struct User User;
float totalUnits(User *u) {
	int i;
    float total = 0;
    for (i = 0; i < u->daysRecorded; i++) {
        total += u->units[i];
    }
    return total;
}

float calculateBill(float total) {
    float bill = 0;
    if (total < 100)
        bill = total * 5;      
    else if (total < 300)
        bill = 100 * 5 + (total - 100) * 7; 
    else
        bill = 100 * 5 + 200 * 7 + (total - 300) * 10; 
    return bill;
}

int main() {
    User u;
    int initialDays; int i;
    
    printf("Enter user name: ");
    scanf(" %[^\n]", u.name);
    
    printf("Enter number of days to record initially: ");
    scanf("%d", &initialDays);
    
    u.daysRecorded = initialDays;
    u.units = malloc(u.daysRecorded * sizeof(float));
    
    for (i = 0; i < u.daysRecorded; i++) {
        printf("Enter units consumed on day %d: ", i + 1);
        scanf("%f", &u.units[i]);
    }
    
    int extend;
    printf("Do you want to add more days? (1 = Yes, 0 = No): ");
    scanf("%d", &extend);
    
    if (extend == 1) {
        int extraDays;
        printf("How many more days to add? ");
        scanf("%d", &extraDays);
        
        u.units = realloc(u.units, (u.daysRecorded + extraDays) * sizeof(float));
        for (i = u.daysRecorded; i < u.daysRecorded + extraDays; i++) {
            printf("Enter units consumed on day %d: ", i + 1);
            scanf("%f", &u.units[i]);
        }
        u.daysRecorded += extraDays;
    }
    
    float total = totalUnits(&u);
    float bill = calculateBill(total);
    float average = total / u.daysRecorded;
    
    printf("\n=== Electricity Bill Summary ===\n");
    printf("User Name: %s\n", u.name);
    printf("Days Recorded: %d\n", u.daysRecorded);
    printf("Total Units: %.2f\n", total);
    printf("Average Daily Units: %.2f\n", average);
    printf("Bill Amount: Rs %.2f\n", bill);
    
    FILE *f = fopen("bill_summary.txt", "w");
    if (!f) {
        printf("Error creating file!\n");
    } else {
        fprintf(f, "=== Electricity Bill Summary ===\n");
        fprintf(f, "User Name: %s\n", u.name);
        fprintf(f, "Days Recorded: %d\n", u.daysRecorded);
        fprintf(f, "Total Units: %.2f\n", total);
        fprintf(f, "Average Daily Units: %.2f\n", average);
        fprintf(f, "Bill Amount: Rs %.2f\n", bill);
        fclose(f);
        printf("Summary saved to bill_summary.txt\n");
    }
    
    free(u.units);
    
    return 0;
}


