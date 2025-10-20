#include <stdio.h>

int main() {
    int marks[12], positive[12], negative[12];
    int i, poscount = 0, negcount = 0;

    for(i = 0; i < 12; i++) {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("\n Grade Report \n");
    for(i = 0; i < 12; i++) {
        int m = marks[i];

        if(m >= 90 && m <= 100) { printf("Student %d: A+\n", i+1); positive[poscount++] = m; }
        else if(m >= 86) { printf("Student %d: A\n", i+1); positive[poscount++] = m; }
        else if(m >= 82) { printf("Student %d: A-\n", i+1); negative[negcount++] = m; }
        else if(m >= 78) { printf("Student %d: B+\n", i+1); positive[poscount++] = m; }
        else if(m >= 74) { printf("Student %d: B\n", i+1); positive[poscount++] = m; }
        else if(m >= 70) { printf("Student %d: B-\n", i+1); negative[negcount++] = m; }
        else if(m >= 66) { printf("Student %d: C+\n", i+1); positive[poscount++] = m; }
        else if(m >= 62) { printf("Student %d: C\n", i+1); positive[poscount++] = m; }
        else if(m >= 58) { printf("Student %d: C-\n", i+1); negative[negcount++] = m; }
        else if(m >= 54) { printf("Student %d: D+\n", i+1); positive[poscount++] = m; }
        else if(m >= 50) { printf("Student %d: D\n", i+1); positive[poscount++] = m; }
        else { printf("Student %d: F\n", i+1); negative[negcount++] = m; }
    }

    if(negcount > 6)
        printf("\nAcademic Alert: Poor Performance!\n");

    printf("\nStudents with Positive Grades: ");
    for(i = 0; i < poscount; i++)
        printf("%d ", positive[i]);

    printf("\nStudents with Negative Grades: ");
    for(i = 0; i < negcount; i++)
        printf("%d ", negative[i]);

    printf("\n");

    return 0;
}


