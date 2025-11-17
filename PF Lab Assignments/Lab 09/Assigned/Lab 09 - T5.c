#include <stdio.h>

void analyze_attendance(int rows, int cols, int attendance[rows][cols]);

int main() {
    int students = 30, days = 5;
    int attendance[30][5];
    int i, j;

    printf("Enter attendance for 30 students for 5 days (1 for present, 0 for absent):\n");

    for (i = 0; i < students; ++i) {
        printf("\nStudent %d:\n", i + 1);
        for (j = 0; j < days; ++j) {
            printf("  Day %d (1=Present, 0=Absent): ", j + 1);
            if (scanf("%d", &attendance[i][j]) != 1) {
                printf("Invalid input. Exiting.\n");
                return 0;
            }
            
            if (attendance[i][j] != 0 && attendance[i][j] != 1)
                attendance[i][j] = 0;
        }
    }

    analyze_attendance(students, days, attendance);
    return 0;
}

void analyze_attendance(int rows, int cols, int attendance[rows][cols]) {
    int defaulters = 0;
    int i,j;

    for (i = 0; i < rows; ++i) {
        int present = 0; // reset for each student
        for (j = 0; j < cols; ++j) {
            present += attendance[i][j];
        }

        float percent = (present * 100.0) / cols;
        printf("Student %2d: Present %d/%d -> %.2f%% - ", i + 1, present, cols, percent);

        if (percent >= 85.0)
            printf("Good\n");
        else if (percent >= 75.0)
            printf("Average\n");
        else {
            printf("Poor\n");
            defaulters++;
        }
    }

    printf("\nTotal defaulters (attendance < 75%%): %d\n", defaulters);
}


