#include <stdio.h>

float calcAvg(float *ptr);
char getGrade(float avg);
int findTopper(float avg[], int n);
int main() {
    float marks[5][3], avg[5];
    char grade[5];
    int i, j;

    printf("Enter marks of 5 students in 3 subjects:\n");

    for (i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &marks[i][j]);
        }
    }

  
    int (*ptrTop)(float[], int);
    ptrTop = findTopper;

 
    for (i = 0; i < 5; i++) {
        avg[i] = calcAvg(marks[i]);   
        grade[i] = getGrade(avg[i]);
        printf("\nStudent %d -> Average: %.2f, Grade: %c", i + 1, avg[i], grade[i]);
    }

    int topIndex = ptrTop(avg, 5);
    printf("\n\nTopper is Student %d with Average: %.2f (Grade: %c)\n",
           topIndex + 1, avg[topIndex], grade[topIndex]);

    return 0;
}


float calcAvg(float *ptr) {
    float sum = 0;
    int i;
    for (i = 0; i < 3; i++)
        sum += *(ptr + i);  
    return sum / 3;
}

char getGrade(float avg) {
    if (avg >= 85) return 'A';
    else if (avg >= 70) return 'B';
    else if (avg >= 55) return 'C';
    else if (avg >= 40) return 'D';
    else return 'F';
}

int findTopper(float avg[], int n) {
    int top = 0;
    int i;
    for (i = 1; i < n; i++) {
        if (avg[i] > avg[top])
            top = i;
    }
    return top;
}




