#include<stdio.h>
int main () {
    int status[15] = {0,0,0,1,1,0,1,1,0,1,1,0,0,1,1};
    int delayed[15] = {1,1,2,0,0,2,0,0,3,0,0,4,1,0,0};
    int fine[15];
    int i, totalfine = 0;

    printf("================================ Student Fee Payment Status Report ================================\n\n");

    for (i = 0; i < 15; i++) {
        if (status[i] == 1) {
            fine[i] = 0;
            printf("Student %d\t\tStatus: Paid\t\tFine: Rs.%d\t\tMonths Due: %d\t\tRemark: Cleared\n",
                   i+1, fine[i], delayed[i]);
        } 
        else {
            if (delayed[i] == 1) {
                fine[i] = 500;
            } 
            else if (delayed[i] == 2) {
                fine[i] = 1000;
            } 
            else if (delayed[i] == 3) {
                fine[i] = 1500;
            } 
            else if (delayed[i] >= 4) {
                fine[i] = 2000;
            } 
            else {
                fine[i] = 0;
            }

            printf("Student %d\t\tStatus: Not Paid\tFine: Rs.%d\t\tMonths Due: %d\t\tRemark: Defaulter\n",
                   i+1, fine[i], delayed[i]);
        }

        totalfine += fine[i];
    }

    printf("\n\nTotal Fine Collected: Rs.%d\n", totalfine);
    return 0;
}




