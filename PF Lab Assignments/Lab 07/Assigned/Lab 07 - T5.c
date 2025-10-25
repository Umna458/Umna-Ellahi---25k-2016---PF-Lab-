#include<stdio.h>
int main () {
	int sections[6] = {28,60,43,34,77,12};
	int in[6], i;
	int total = 0, total_in = 0;
	
	printf("========= Invigilator Chart =========\n\n");
	for (i = 0; i < 6; i++) {
		if (sections[i] <= 30) {
			in[i] = 1;
		}
		else if (sections[i] > 30 && sections[i] <= 60) {
			in[i] = 2;
		}
		else {
			in[i] = 3;
		}
		
		total += sections[i];
		total_in += in[i];
		printf("Section %d\tTotal Invigilators: %d\n", i+1, in[i]);
	}
	
	if (total > 300) {
		printf("\nAssign a Cheif Invigilator.");
		total_in = total_in +1;
	}
	printf("\nTotal Students: %d\n", total);
	printf("Total invigilators: %d", total_in);
	
	
	return 0;
}


