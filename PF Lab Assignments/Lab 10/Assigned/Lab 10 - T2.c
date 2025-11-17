#include<stdio.h>
#include<stdlib.h>

int main() {
	char st_name[50];
	int st_count = 0;
	FILE *fattendance;
	
	fattendance = fopen("C:\\attendance.txt", "r");
	
	if (fattendance == NULL) {
		printf("ERROR! Unable to opne file!\n");
		exit(1);
	}
	
	printf("=== ATTENDANCE RECORD ===\n");
	
	while (fscanf(fattendance, "%s", st_name) != EOF) {
        printf("Name: %s\n", st_name);  
        st_count++;                      
    }

    printf("\nTotal students in file: %d\n", st_count);

    fclose(fattendance);

    return 0;
	

}


