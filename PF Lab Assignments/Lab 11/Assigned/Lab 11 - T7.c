#include <stdio.h>

int maxTip(int tips[], int n) {
    if (n == 0) return 0;       
    if (n == 1) return tips[0]; 

    int takeCurrent = tips[n - 1] + maxTip(tips, n - 2);

    int skipCurrent = maxTip(tips, n - 1);

    return (takeCurrent > skipCurrent) ? takeCurrent : skipCurrent;
}

int main() {
    int n, i;

    printf("Enter number of delivery stops: ");
    scanf("%d", &n);

    int tips[n];
    for (i = 0; i < n; i++) {
        printf("Enter tip amount at stop %d: ", i + 1);
        scanf("%d", &tips[i]);
    }

    int max_total_tip = maxTip(tips, n);

    printf("\nMaximum Tip the Rider Can Collect: %d\n", max_total_tip);

    return 0;
}




