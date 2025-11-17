#include <stdio.h>
void dispense_cash(int amount, int *denominations, int *counts, int n);
int main() {
    int amount, i;
    int denominations[] = {5000, 1000, 500};
    int n = sizeof(denominations) / sizeof(denominations[0]);
    int counts[3] = {0};
    int *pdenoms = denominations;
    int *pcounts = counts;

    printf("Enter withdrawal amount (Rs): ");
    if (scanf("%d", &amount) != 1) 
		return 0;

    if (amount <= 0 || amount % 50 != 0) {
        printf("Invalid amount! Amount must be a positive multiple of 50.\n");
        return 0;
    }

    dispense_cash(amount, pdenoms, pcounts, n); // call func

    printf("Dispensed:\n");
    for (i = 0; i < n; ++i) {
        printf("Rs. %d : %d\n", *(pdenoms + i), *(pcounts + i));
    }
    return 0;
}

void dispense_cash(int amount, int *denominations, int *counts, int n) {
	int i;
	
    for (i = 0; i < n; ++i) {
        counts[i] = amount / denominations[i];
        amount -= counts[i] * denominations[i];
    }
}




