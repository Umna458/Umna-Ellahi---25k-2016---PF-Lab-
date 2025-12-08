#include <stdio.h>

struct Patient {
    char patient_name[50];
    int age;
    float health_score;   
};

struct DailyReport {
    int day;
    float score_change;   
};

float final_score(struct Patient *P, struct DailyReport report[], int n) {
    if (n == 0) {
        return P->health_score;
    }
    
    float previous = final_score(P, report, n - 1);
    float updated = previous + report[n - 1].score_change;
    
    return updated;
}

int main() {
    struct Patient P1;
    int n, i;
    
    printf("Enter Patient Name: ");
    scanf("%s", P1.patient_name);

    printf("Enter Age: ");
    scanf("%d", &P1.age);

    printf("Enter Initial Health Score: ");
    scanf("%f", &P1.health_score);    

    printf("Enter number of days to monitor: ");
    scanf("%d", &n);

    struct DailyReport reports[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter Day %d Score Change: ", i + 1);
        scanf("%f", &reports[i].score_change);   
        reports[i].day = i + 1;
    }

    float final_health_score = final_score(&P1, reports, n);

    printf("\n=== Patient Health Monitoring ===\n");
    printf("Patient Name: %s\n", P1.patient_name);
    printf("Age: %d\n", P1.age);
    printf("Initial Health Score: %.2f\n", P1.health_score);
    printf("Days Monitored: %d\n", n);
    printf("Final Health Score After %d Days: %.2f\n", n, final_health_score);

    return 0;
}



