#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char city[5][50];
	float avg_temp[5];
	int i;
	
	char rcity[50];
	float ravg_temp;
	float max_temp = -1000;
	char hottest_city[50];
	char line[100];

	FILE *ftemp;
	
	ftemp = fopen("C:\\temperature.txt", "w");
	
	if (ftemp == NULL) {
		printf("ERROR! Unable to opne file!\n");
		exit(1);
	}
	
	printf("=== TEMPERATURE LOGGER ===\n");
	for(i=0; i<5; i++) {
		printf("Enter city name: ");
		scanf(" %[^\n]", city[i]);
		printf("Enter the average temperature: ");
		scanf("%f", &avg_temp[i]);
		
		fprintf(ftemp, "%s %.2f\n", city[i], avg_temp[i]);
	}
	
	fclose(ftemp);
	
	ftemp = fopen("C:\\temperature.txt", "r");
	if (ftemp == NULL) {
		printf("ERROR! Unable to open file!\n");
		exit(1);
	}
	
	
	while(fgets(line,sizeof(line), ftemp)) {
		sscanf(line,"%s %f", rcity, &avg_temp);
	
			if(ravg_temp > max_temp) {
				max_temp = ravg_temp; //will save in hottest city 
				strcpy(hottest_city, rcity); //rcity is the city name being read
			
		}
	}
	
	fclose(ftemp);
	
	printf("\nCity with highest temperature: %s (%.2f)\n", hottest_city, max_temp);
	
	return 0;
}
	
	
	
	
