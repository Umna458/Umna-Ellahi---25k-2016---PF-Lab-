#include <stdio.h>
#include <string.h>

int main() {
    char names[10][50], temp[50];
    int i, j;

    printf("Enter 10 student names:\n");
    for (i = 0; i < 10; i++) {
        printf("Name %d: ", i + 1);
        gets(names[i]);   
    }

    // Sort names alphabetically
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("\n=== Sorted Student Names (A-Z) ===\n");
    for (i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}


