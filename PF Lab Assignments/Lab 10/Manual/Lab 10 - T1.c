#include <stdio.h>
#include <string.h>

int main() {
    char feedback[30], updated[40];  
    char *ptr;

    printf("Enter customer feedback: ");
    gets(feedback);  

    int length = strlen(feedback);
    printf("\nTotal characters: %d\n", length);

    if (strstr(feedback, "bad"))
        printf("The feedback contains the word 'bad'.\n");
    else if (strstr(feedback, "good"))
        printf("The feedback contains the word 'good'.\n");
    else
        printf("No 'bad' or 'good' word found.\n");

    ptr = strstr(feedback, "bad");
    if (ptr != NULL) {                
        int index = ptr - feedback;

        strncpy(updated, feedback, index);
        updated[index] = '\0';        

        strcat(updated, "not good");

        strcat(updated, feedback + index + 3);

        printf("\nUpdated Feedback: %s\n", updated);
    } else {
        printf("\nNo 'bad' found to replace.\n");
    }

    return 0;
}


