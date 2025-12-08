#include <stdio.h>
#include <string.h>

struct Customer {
    char name[50];
    char meterID[20];
    int units_consumed;
    float finalBill;
};

float calculate_tax(int units) {
    if (units <= 0) return 0;
    if (units <= 100) return units * 5 / 100.0;
    else if (units <= 300) return 100 * 5 / 100.0 + calculate_tax(units - 100);
    else return 100 * 5 / 100.0 + 200 * 12 / 100.0 + calculate_tax(units - 300);
}

void calculate_bill(struct Customer *c, float unitPrice) {
    float baseAmount = c->units_consumed * unitPrice;
    float taxAmount = calculate_tax(c->units_consumed);
    c->finalBill = baseAmount + taxAmount;
}

int main() {
	struct Customer c1;

    printf("Enter Customer Name: ");
    fgets(c1.name, sizeof(c1.name), stdin);
    c1.name[strcspn(c1.name, "\n")] = 0; 

    printf("Enter Meter ID: ");
    fgets(c1.meterID, sizeof(c1.meterID), stdin);
    c1.meterID[strcspn(c1.meterID, "\n")] = 0; 
    
    printf("Enter Units Consumed: ");
    scanf("%d", &c1.units_consumed);

    calculate_bill(&c1, 10.0);

    printf("\n=== Customer Bill ===\n");
    printf("Customer Name: %s\n", c1.name);
    printf("Meter ID: %s\n", c1.meterID);
    printf("Units Consumed: %d\n", c1.units_consumed);
    printf("Total Bill: %.2f\n", c1.finalBill);

    return 0;
	
}


