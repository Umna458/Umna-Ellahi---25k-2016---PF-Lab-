#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// ------------------- MODULE 1: MOOD INPUT -------------------
void moodInput() {
    char mood;
    printf("\nWhat is your mood today?\n");
    printf("--------------------------\n");
    printf("Press H = Happy\n");
    printf("Press S = Sad\n");
    printf("Press A = Angry\n");
    printf("Press E = Excited\n");
    printf("Press N = Neutral\n");
    printf("--------------------------\n");
    printf("Enter your choice: ");
    scanf(" %c", &mood);
    while(getchar() != '\n'); // clear leftover newline

    switch (mood) {
        case 'H': case 'h': printf("\nKeep smiling, because life is a beautiful thing.\n"); break;
        case 'S': case 's': printf("\nIt's okay to feel sad sometimes.\n"); break;
        case 'A': case 'a': printf("\nLet your anger fuel your passion.\n"); break;
        case 'E': case 'e': printf("\nEmbrace the excitement of new possibilities.\n"); break;
        case 'N': case 'n': printf("\nStay calm and carry on.\n"); break;
        default: printf("\nInvalid Input - Try Again\n"); return;
    }
}

// ------------------- MODULE 2: JOURNAL -------------------
int word_count(char *text) {
    int i, count = 0, inside_word = 0;
    for (i = 0; text[i] != '\0'; i++) {
        if (!isspace(text[i]) && !inside_word) { count++; inside_word = 1; }
        else if (isspace(text[i])) inside_word = 0;
    }
    return count; // word count
}

int Entries() {
    FILE *file = fopen("soul_sync.txt", "r");
    if (!file) return 0;
    char line[3000]; int entry_count=0;
    
    while (fgets(line,sizeof(line),file)) {
        line[strcspn(line,"\n")]=0;
        if (strlen(line)>0) entry_count++;
    }
    fclose(file);
    return entry_count;
}

void journalModule() {
    char entry[3000], line[3000], choice[10], ch;
    int i;
    while (1) {
        printf("\n=== JOURNAL MENU ===\n1. Add new entry\n2. View all entries\n3. Exit\n-----------------\nEnter choice: ");
        if (fgets(choice,sizeof(choice),stdin)==NULL) continue;
        if (sscanf(choice,"%c",&ch)!=1) continue;
        if (ch=='1') {
            int total = Entries();
            if (total >= 5) {
                printf("\nEntry limit reached!\n");
                continue;
            }
            printf("\nWrite entry [150 words only]:\n");
            fgets(entry, sizeof(entry), stdin);
            for (i = 0; entry[i]; i++)
                if (entry[i] == '\n')
                    entry[i] = ' ';
            int words = word_count(entry);
            if (words > 150) {
                printf("\nEntry NOT saved. Words: %d [Word limit reached]\n", words);
                continue;
            }
            FILE *file = fopen("soul_sync.txt", "a");
            if (!file) {
                printf("\nERROR - FILE NOT RESPONDING\n");
                continue;
            }
            fprintf(file, "%s\n", entry);
            fclose(file);
            int remaining = 5 - (total + 1);   
            printf("\nEntry saved successfully - %d words\n", words);
            printf("You have %d entries remaining.\n", remaining); 
        }
        else if (ch=='2') {
            FILE *file=fopen("soul_sync.txt","r");
            if (!file) { printf("\nNo entries yet.\n"); continue; }
            printf("\n===== SAVED ENTRIES =====\n\n");
            int num=1;
            while (fgets(line,sizeof(line),file)) {
                line[strcspn(line,"\n")]=0;
                if (strlen(line)==0) continue;
                printf("%d: %s\n",num,line); num++;
            }
            fclose(file);
        }
        else if (ch=='3') break;
        else printf("\nInvalid choice!\n");
    }
}

// ------------------- MODULE 3: MOOD ANALYTICS -------------------
// Converts a date string "YYYY-MM-DD" into a time_t value for comparison
time_t convert_to_time(const char *dateStr) {
    struct tm tm_date = {0};
    // Extract year, month, day
    if (sscanf(dateStr, "%d-%d-%d", &tm_date.tm_year, &tm_date.tm_mon, &tm_date.tm_mday) != 3)
        return (time_t)-1; // return invalid if format is wrong
    tm_date.tm_year -= 1900;  // tm_year = years since 1900
    tm_date.tm_mon  -= 1;     // tm_mon = 0 to 11
    return mktime(&tm_date);  // convert structured date to time_t
}
// Checks if a given time corresponds to a date after today
int is_future_date(time_t t) {
    // Get today's date
    time_t today = time(NULL);
    struct tm current = *localtime(&today);
    // Reset time to 00:00:00 (start of day)
    current.tm_hour = 0;
    current.tm_min  = 0;
    current.tm_sec  = 0;
    // Convert back to time_t
    time_t todayStart = mktime(&current);
    return t > todayStart; // TRUE if the date is ahead of today
}
// Main analytics function that reads mood records and generates summary
void mood_analytics() {
    // Open mood data file
    FILE *file = fopen("mood_data.txt","r");
    if (!file) {
        printf("\nError: Could not open mood_data.txt\n");
        return;
    }
    char start[11], end[11], date[11], mood[20];
    // Predefined moods
    const char *moods[] = {"Happy", "Sad", "Angry", "Neutral", "Excited"};
    // Counters for each mood
    int counts[5] = {0}, total = 0;
    // Ask user for start and end dates
    printf("\nEnter start date (YYYY-MM-DD): ");
    scanf("%10s", start);
    printf("Enter end date (YYYY-MM-DD): ");
    scanf("%10s", end);
    // Convert dates to time_t
    time_t startT = convert_to_time(start);
    time_t endT   = convert_to_time(end);
    // Validate date range
    if (startT == (time_t)-1 || endT == (time_t)-1) { // because starting from 0 and not 1
        printf("\nError: Invalid date format.\n");
        fclose(file);
        return;
    }
    if (startT > endT) {
        printf("\nError: Start date cannot be after end date.\n");
        fclose(file);
        return;
    }
    if (is_future_date(startT) || is_future_date(endT)) {
        printf("\nError: Date range contains a future date.\n");
        fclose(file);
        return;
    }
    printf("\n=== Mood Records From %s to %s ===\n", start, end);
    // Read file line by line
    while (fscanf(file, "%10s %19s", date, mood) == 2) {
        // Convert date from file
        time_t recordTime = convert_to_time(date);
        // Skip invalid date lines
        if (recordTime == (time_t)-1)
            continue;
        // Stop if file contains a future date
        if (is_future_date(recordTime)) {
            printf("\nError: File contains a future date: %s\n", date);
            fclose(file);
            return;
        }
        // Only process if date falls in user-selected range
        if (recordTime >= startT && recordTime <= endT) {
            printf("%s  -  %s\n", date, mood);
            // Increase the correct mood counter
            int i;
            for (i = 0; i < 5; i++)
                if (strcmp(mood, moods[i]) == 0)
                    counts[i]++;
            total++; // count total entries
        }
    }
    fclose(file);
    // If no entries found
    if (total == 0) {
        printf("\nNo records found in this date range.\n");
        return;
    }
    // Print summary
    int i;
    printf("\n=== Mood Analytics Summary ===\n");
    printf("Total Records Analyzed: %d\n\n", total);
    for (i = 0; i < 5; i++)
        printf("%-8s: %d entries | %.2f%%\n",
               moods[i],
               counts[i],
               (counts[i] * 100.0) / total);
}

// ------------------- MODULE 4: SETTINGS -------------------
char specialChars[3] = {'@','#','$'};
char securityQ1[] = "What is your favorite color?";
char securityA1[] = "blue";
char securityQ2[] = "What city were you born in?";
char securityA2[] = "paris";
char storedPassword[50] = "";
int passwordExists = 0;
int theme = 1;
int notifications = 1;

void clearInput() { while(getchar() != '\n'); }

int validatePassword(char pass[]) {
    int i,j,len=strlen(pass),alpha=0,digit=0,special=0;
    if(len<8){ printf("Password must be at least 8 characters.\n"); return 0; }
    for(i=0;i<len;i++){
        if(isalpha(pass[i])) alpha++;
        else if(isdigit(pass[i])) digit++;
        else{ int valid=0; for(j=0;j<3;j++) if(pass[i]==specialChars[j]) valid=1;
            if(valid) special++; else { printf("Invalid special char: %c\n",pass[i]); return 0; } }
    }
    if(alpha<3){ printf("At least 3 letters needed.\n"); return 0; }
    if(digit<3){ printf("At least 3 numbers needed.\n"); return 0; }
    if(special<2){ printf("At least 2 special chars needed.\n"); return 0; }
    return 1;
}

int askSecurityQuestions() {
    char ans1[50], ans2[50]; int i;
    printf("%s\nYour answer: ", securityQ1); scanf("%s", ans1); clearInput();
    printf("%s\nYour answer: ", securityQ2); scanf("%s", ans2); clearInput();

    for(i=0; ans1[i]; i++) ans1[i]=tolower(ans1[i]);
    for(i=0; ans2[i]; i++) ans2[i]=tolower(ans2[i]);

    return strcmp(ans1,securityA1)==0 && strcmp(ans2,securityA2)==0; // if 0 then indentical, match is found
}

void passwordMenu() {
    char pass[50], newPass[50], oldPass[50];
    int choice, option, attempts;
    if(!passwordExists) {
        printf("\nNo password exists. Set new password? (1=Yes, 0=No): "); scanf("%d",&choice); clearInput();
        if(choice==1){
            printf("\n---- Password Requirements ----\n");
            printf("1. Length should be 8 or more characters.\n");
            printf("2. At least 3 digits.\n");
            printf("3. At least 2 special characters.\n");
            printf("4. Allowed special chars: %c %c %c\n", specialChars[0], specialChars[1], specialChars[2]);
            printf("Enter new password: "); scanf("%s", pass); clearInput();
            if(validatePassword(pass)) { strcpy(storedPassword,pass); passwordExists=1; printf("Password created successfully.\n"); }
            else { printf("Password invalid. Setup aborted.\n"); return; }
        } else return;
    }

    while(1){
        printf("\n--- PASSWORD MENU ---\n1. Change Password\n2. Forgot Password\n3. Back\nEnter choice: "); scanf("%d",&option); clearInput();
        if(option==1){
            printf("Enter current password: "); scanf("%s", oldPass); clearInput();
            if(strcmp(oldPass,storedPassword)!=0){ printf("Incorrect password.\n"); continue; }
            attempts=3;
            while(attempts>0 && !askSecurityQuestions()){ attempts--; printf("Security answers incorrect. Attempts remaining: %d\n",attempts); }
            if(attempts==0){ printf("Security verification failed.\n"); continue; }
            printf("Enter new password: "); scanf("%s", newPass); clearInput();
            if(validatePassword(newPass)) { strcpy(storedPassword,newPass); printf("Password updated successfully!\n"); }
            else printf("Password invalid.\n");
        }
        else if(option==2){
            attempts=3;
            while(attempts>0 && !askSecurityQuestions()){ attempts--; printf("Security answers incorrect. Attempts remaining: %d\n",attempts); }
            if(attempts==0){ printf("Security verification failed.\n"); continue; }
            printf("Enter new password: "); scanf("%s", newPass); clearInput();
            if(validatePassword(newPass)) { strcpy(storedPassword,newPass); printf("Password reset successfully!\n"); }
            else printf("Password invalid.\n");
        }
        else if(option==3) break;
        else printf("Invalid choice.\n");
    }
}

void changeTheme() {
    int ch;
    printf("\nSelect Theme:\n1. Dark\n2. Light\nEnter choice: "); scanf("%d",&ch); clearInput();
    if(ch==1||ch==2){ theme=ch; printf("Theme updated.\n"); } else printf("Invalid theme choice.\n");
}

void toggleNotifications() {
    int choice;
    printf("\nNotifications currently %s.\nToggle? (1=Yes,0=No): ", notifications?"ON":"OFF");
    scanf("%d",&choice); clearInput();
    if(choice==1){ notifications=!notifications; printf("Notifications updated.\n"); }
    else if(choice==0) printf("No changes made.\n"); else printf("Invalid input.\n");
}

void showSettingsMenu() {
    printf("\n---------- SETTINGS ----------\n");
    printf("1. Theme (Current: %s)\n", theme==1?"Dark":"Light");
    printf("2. Password (%s)\n", passwordExists?"Set":"Not Set");
    printf("3. Notifications (%s)\n", notifications?"ON":"OFF");
    printf("4. Back\n------------------------------\n");
}

void settingsModule() {
    int running=1, choice;
    while(running){
        showSettingsMenu();
        printf("Enter choice: "); scanf("%d",&choice); clearInput();
        switch(choice){
            case 1: changeTheme(); break;
            case 2: passwordMenu(); break;
            case 3: toggleNotifications(); break;
            case 4: running=0; break;
            default: printf("Invalid choice.\n");
        }
    }
}

// -------------------- MAIN MENU -------------------
int main() {
    char mainchoice;
    printf("=====================================================================\n");
    printf("                      WELCOME TO SoulSync!\n");
    printf("=====================================================================\n");
    while(1){
        printf("\n===== Main Menu =====\n");
        printf("1. Mood Input\n2. Journal\n3. Mood Analytics\n4. Settings\n5. Exit\n----------------------\nEnter choice: ");
        scanf(" %c",&mainchoice);
        while(getchar() != '\n'); // clear newline

        switch(mainchoice){
            case '1': moodInput(); break;
            case '2': journalModule(); break;
            case '3': mood_analytics(); break;
            case '4': settingsModule(); break;
            case '5': printf("\n\nExiting SoulSync... Goodbye!\n"); exit(0);
            default: printf("\nInvalid choice.\n");
        }
    }
    return 0;
}
