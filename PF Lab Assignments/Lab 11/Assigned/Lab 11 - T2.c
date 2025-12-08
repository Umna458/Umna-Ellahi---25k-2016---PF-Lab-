#include <stdio.h>
#include <string.h>

struct Loan {
    char customer_name[50];
    double loan_amount;
    double interest_rate;
    int months;
    double monthly_installment;
};

double Payment(struct Loan *l, int n) {
    if (n == 0 || l->loan_amount <= 0) {
        return l->loan_amount;
    }

    double initial = Payment(l, n - 1);

    double interest = initial * l->interest_rate;

    double remaining = initial - l->monthly_installment + interest;

    return remaining;
}

int main() {
    struct Loan l1;

    printf("Enter Customer Name: ");
    scanf("%s", l1.customer_name);

    printf("Enter Loan Amount: ");
    scanf("%lf", &l1.loan_amount);

    printf("Enter Monthly Interest Rate (e.g., 0.02 for 2%%): ");
    scanf("%lf", &l1.interest_rate);

    printf("Enter Total Months: ");
    scanf("%d", &l1.months);

    printf("Enter Monthly Installment: Rs ");
    scanf("%lf", &l1.monthly_installment);

    double remaining_amount = Payment(&l1, l1.months);

    if (remaining_amount < 0) {
        remaining_amount = 0;  
    }

    printf("\n=== Banking System Loan Repayment Estimator ===\n");
    printf("Customer Name: %s\n", l1.customer_name);
    printf("Initial Loan Amount: Rs %.2lf\n", l1.loan_amount);
    printf("Monthly Installment: Rs %.2lf\n", l1.monthly_installment);
    printf("Months Simulated: %d\n", l1.months);
    printf("Remaining Balance After Payments: Rs %.2lf\n", remaining_amount);

    return 0;
}




