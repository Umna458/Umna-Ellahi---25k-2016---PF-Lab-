#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Med {
    char name[50];
    int qty;
    float price;
};

int main() {
    int n = 0, i = 0, choice;
    struct Med *m = NULL;
    FILE *fp;

    while(1) {
        printf("\n1 Add\n2 Remove Last\n3 Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            m = (struct Med*)realloc(m, (n+1)*sizeof(struct Med));
            printf("Name: "); scanf("%s", m[n].name);
            printf("Qty: "); scanf("%d", &m[n].qty);
            printf("Price: "); scanf("%f", &m[n].price);
            n++;
        }
        else if(choice == 2 && n > 0) {
            printf("Removed last medicine: %s\n", m[n-1].name);
            n--;
            m = (struct Med*)realloc(m, n*sizeof(struct Med));
        }
        else if(choice == 3) break;
        else {
            printf("Invalid choice or nothing to remove.\n");
        }
    }

    fp = fopen("medicine_inventory.txt", "w");
    float total = 0;

    printf("\n==============================\n");
    printf("Medicine Inventory Summary:\n");
    printf("==============================\n");
    printf("Name\tQty\tPrice\tValue\n");

    for(i = 0; i < n; i++) {
        float value = m[i].qty * m[i].price;
        fprintf(fp, "%s %d %.2f\n", m[i].name, m[i].qty, m[i].price);
        printf("%s\t%d\t%.2f\t%.2f\n", m[i].name, m[i].qty, m[i].price, value);
        total += value;
    }

    fprintf(fp, "TotalValue=%.2f\n", total);
    printf("------------------------------\n");
    printf("Total Inventory Value: %.2f\n", total);

    fclose(fp);
    free(m);
    return 0;
}



S
