#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char g_name[5][50];
	char searchname;
	int room[5];
	int i;
	
	char tempname[50];
	int temproom;
	int found = 0;
	
	FILE *fhotel;
	
	fhotel = fopen("C:\\hotel.txt", "w");
	
	if (fhotel == NULL) {
		printf("ERROR! Unable to open file!\n");
		exit(1);
	}
	
	printf("=== HOTEL BOOKING RECORD SYSTEM ===\n");
	
	for( i=0; i<5; i++) {
		printf("Enter your name: ");
		scanf(" %[^\n]", g_name[i]);
		
		printf("Enter room number: ");
		scanf("%d", &room[i]);
		
		fprintf(fhotel, "%s %d\n", g_name[i], room[i]);
	}
	
	fclose(fhotel);
	
	printf("\nEnter name of guest to be searched: ");
	scanf(" %[^\n]", searchname);
	
	fhotel = fopen("C:\\hotel.txt", "r");
	
	while(fscanf(fhotel, "%s %d", tempname, temproom) != EOF) {
		if(strcmp(tempname, searchname) == 0) {
			printf("\nGuest Found.\n");
			printf("Name: %s\nRoom Number: %d\n", tempname, temproom);
			found = 1;
			break;
		}
	}
	
	fclose(fhotel);
	
	if(found == 0)
		printf("\nGuest Not Found.\n");
		
	return 0;	
}



