#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

struct Student {
    struct Person person;
    float perCreditFee;
    int creditHours[50]; 
    int numSubjects;
};

float Fee(struct Student *s, int n) {
    if (n == 0) {
        return 0; 
    } else {
        return Fee(s, n - 1) + (s->creditHours[n - 1] * s->perCreditFee);
    }
}

int main() {
    struct Student s1;
    int i;

    printf("Enter Student Name: ");
    scanf("%s", s1.person.name);

    printf("Enter Age: ");
    scanf("%d", &s1.person.age);

    printf("Enter Per Credit Fee: ");
    scanf("%f", &s1.perCreditFee);

    printf("Enter Number of Subjects: ");
    scanf("%d", &s1.numSubjects);

    for (i = 0; i < s1.numSubjects; i++) {
        printf("Enter Credit Hours for Subject %d: ", i + 1);
        scanf("%d", &s1.creditHours[i]);
    }

    float totalFee = Fee(&s1, s1.numSubjects);
    
    printf("\n=== University Fee ===\n");
    printf("Student Name: %s\n", s1.person.name);
    printf("Age: %d\n", s1.person.age);
    printf("Number of Subjects: %d\n", s1.numSubjects);
    printf("Per Credit Fee: %.2f\n", s1.perCreditFee);
    printf("Total Semester Fee: %.2f\n", totalFee);

    return 0;
}
    
    


