#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order {
    char itemName[50];
    int quantity;
    float unitPrice;
    char customerName[50];
};

int main() {
    struct Order *orders = NULL;
    int count = 0; int i;
    char choice;
    float totalRevenue = 0;

    do {
        if (count == 0) {
            orders = (struct Order*)malloc(sizeof(struct Order));
        } else {
            orders = (struct Order*)realloc(orders, (count + 1) * sizeof(struct Order));
        }

        if (orders == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("\nEnter Customer Name: ");
        scanf(" %[^\n]", orders[count].customerName);

        printf("Enter Food Item Name: ");
        scanf(" %[^\n]", orders[count].itemName);

        printf("Enter Quantity: ");
        scanf("%d", &orders[count].quantity);

        printf("Enter Unit Price: Rs ");
        scanf("%f", &orders[count].unitPrice);

        totalRevenue += orders[count].quantity * orders[count].unitPrice;

        count++;

        printf("Add another order? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    FILE *file = fopen("orders_receipt.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        free(orders);
        return 1;
    }

    fprintf(file, "==== DAILY ORDER RECEIPT ====\n\n");
    for (i = 0; i < count; i++) {
        fprintf(file, "Order %d:\n", i + 1);
        fprintf(file, "Customer: %s\n", orders[i].customerName);
        fprintf(file, "Item: %s\n", orders[i].itemName);
        fprintf(file, "Quantity: %d\n", orders[i].quantity);
        fprintf(file, "Unit Price: Rs %.2f\n", orders[i].unitPrice);
        fprintf(file, "Total: Rs %.2f\n", orders[i].quantity * orders[i].unitPrice);
        fprintf(file, "-------------------------------\n");
    }
    fprintf(file, "\nTOTAL REVENUE: Rs %.2f\n", totalRevenue);
    fclose(file);

    printf("\nOrders saved to 'orders_receipt.txt' successfully!\n");
    printf("Total Revenue: Rs %.2f\n", totalRevenue);

    free(orders);
    return 0;
}




