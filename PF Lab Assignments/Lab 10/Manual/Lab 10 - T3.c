#include <stdio.h>
#include <string.h>

int main() {
    char email[50], domain[50];
    char *at;

    printf("Enter employee email address: ");
    gets(email);   

    at = strchr(email, '@');

    if (at != NULL) {
        strcpy(domain, at + 1);
        printf("Domain extracted: %s\n", domain);
    } else {
        printf("Invalid email! '@' not found.\n");
    }

    return 0;
}



