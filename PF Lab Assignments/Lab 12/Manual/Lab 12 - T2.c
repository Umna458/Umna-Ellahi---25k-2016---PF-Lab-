#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bed {
    int isOccupied;             
    char patientName[50];       
    int daysAdmitted;
};

typedef struct Bed Bed;
int countOccupied(Bed *beds, int n) {
    if (n == 0)
        return 0;
    return beds[n - 1].isOccupied + countOccupied(beds, n - 1);
}

void saveWardsToFiles(Bed **wards, int *wardSizes, int numWards) {
    char filename[50]; int i,j;
    for (i = 0; i < numWards; i++) {
        sprintf(filename, "ward%d.txt", i + 1);
        FILE *file = fopen(filename, "w");
        if (!file) {
            printf("Error saving ward %d!\n", i + 1);
            continue;
        }

        fprintf(file, "Ward %d\n", i + 1);
        fprintf(file, "Number of Beds: %d\n", wardSizes[i]);
        fprintf(file, "=========================\n");

        for (j = 0; j < wardSizes[i]; j++) {
            fprintf(file, "Bed %d: %s, Days Admitted: %d, Status: %s\n",
                    j + 1,
                    wards[i][j].patientName,
                    wards[i][j].daysAdmitted,
                    wards[i][j].isOccupied ? "Occupied" : "Free");
        }

        fclose(file);
        printf("Ward %d saved to %s\n", i + 1, filename);
    }
}

int main() {
	int i,j;
    int numWards;
    printf("Enter number of wards: ");
    scanf("%d", &numWards);

    int *wardSizes = malloc(numWards * sizeof(int));
    Bed **wards = malloc(numWards * sizeof(Bed *));

    for (i = 0; i < numWards; i++) {
        printf("Enter number of beds in ward %d: ", i + 1);
        scanf("%d", &wardSizes[i]);
        wards[i] = malloc(wardSizes[i] * sizeof(Bed));

        for (j = 0; j < wardSizes[i]; j++) {
            wards[i][j].isOccupied = 0;
            strcpy(wards[i][j].patientName, "Empty");
            wards[i][j].daysAdmitted = 0;
        }
    }

    int choice;
    do {
        printf("\n=== Hospital Bed Tracker ===\n");
        printf("1. Mark bed occupied\n");
        printf("2. Free a bed\n");
        printf("3. Count total occupied beds\n");
        printf("4. Save all wards to files\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        int wardNum, bedNum;
        char name[50];  
        int days;

        switch(choice) {
            case 1:
                printf("Ward number (1-%d): ", numWards);
                scanf("%d", &wardNum);
                printf("Bed number (1-%d): ", wardSizes[wardNum-1]);
                scanf("%d", &bedNum);
                printf("Patient Name: ");
                scanf(" %[^\n]", name);
                printf("Days admitted: ");
                scanf("%d", &days);

                wards[wardNum-1][bedNum-1].isOccupied = 1;
                strcpy(wards[wardNum-1][bedNum-1].patientName, name);
                wards[wardNum-1][bedNum-1].daysAdmitted = days;
                printf("Bed marked occupied.\n");
                break;

            case 2:
                printf("Ward number (1-%d): ", numWards);
                scanf("%d", &wardNum);
                printf("Bed number (1-%d): ", wardSizes[wardNum-1]);
                scanf("%d", &bedNum);

                wards[wardNum-1][bedNum-1].isOccupied = 0;
                strcpy(wards[wardNum-1][bedNum-1].patientName, "Empty");
                wards[wardNum-1][bedNum-1].daysAdmitted = 0;
                printf("Bed freed.\n");
                break;

            case 3: {
                int totalOccupied = 0;
                for (i = 0; i < numWards; i++) {
                    totalOccupied += countOccupied(wards[i], wardSizes[i]);
                }
                printf("Total occupied beds: %d\n", totalOccupied);
                break;
            }

            case 4:
                saveWardsToFiles(wards, wardSizes, numWards);
                break;

            case 5:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    for (i = 0; i < numWards; i++)
        free(wards[i]);
    free(wards);
    free(wardSizes);

    return 0;
}


