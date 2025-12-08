#include <stdio.h>
#include <string.h>

struct Category {
    char categoryName[30];
    char department[30];
};

struct Product {
    char productName[50];
    int expiryDays;
    struct Category category;
};

int Expiry(struct Product *products, int n, int size) {
    if (size == 0)
        return 0; 

    int count = 0;
    if (products->expiryDays <= n) {
        printf("ALERT: Product '%s' from '%s' category in '%s' department expires in %d days!\n",
               products->productName,
               products->category.categoryName,
               products->category.department,
               products->expiryDays);
        count = 1;
    }

    return count + Expiry(products + 1, n, size - 1); 
}

int main() {
    int numProducts, days, totalAlerts;

    printf("Enter the number of products: ");
    scanf("%d", &numProducts);
    getchar();

    struct Product inventory[numProducts];

    for (int i = 0; i < numProducts; i++) {
        printf("\nEnter details for product %d:\n", i + 1);

        printf("Product Name: ");
        fgets(inventory[i].productName, sizeof(inventory[i].productName), stdin);
        inventory[i].productName[strcspn(inventory[i].productName, "\n")] = 0;

        printf("Expiry Days: ");
        scanf("%d", &inventory[i].expiryDays);
        getchar(); 

        printf("Category Name: ");
        fgets(inventory[i].category.categoryName, sizeof(inventory[i].category.categoryName), stdin);
        inventory[i].category.categoryName[strcspn(inventory[i].category.categoryName, "\n")] = 0;

        printf("Department: ");
        fgets(inventory[i].category.department, sizeof(inventory[i].category.department), stdin);
        inventory[i].category.department[strcspn(inventory[i].category.department, "\n")] = 0;
    }

    printf("\nEnter number of days to check for expiry: ");
    scanf("%d", &days);

    printf("\n--- Expiry Alerts ---\n");
    totalAlerts = Expiry(inventory, days, numProducts);

    if (totalAlerts == 0) {
        printf("No products are expiring in the next %d days.\n", days);
    }

    return 0;
}



