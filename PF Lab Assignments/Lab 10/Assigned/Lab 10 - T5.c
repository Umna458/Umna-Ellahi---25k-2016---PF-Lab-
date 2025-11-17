#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int len;

    printf("=== PASSWORD STRENGTH CHECKER ===\n");
    printf("Enter password: ");
    scanf(" %[^\n]", password);

    len = strlen(password);   

    int special = (strchr(password, '@') || strchr(password, '*') || strchr(password, '#'));

    if (len >= 8 && special)
        printf("Password Strength: STRONG\n");

    else if (len >= 5 && special)
        printf("Password Strength: MEDIUM\n");

    else if (len > 0)
        printf("Password Strength: WEAK\n");

    return 0;
}


