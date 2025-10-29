#include<stdio.h>
int main () {
	int marks[2][3][3];
	int total[2][3] = {0}, classtop[2] = {0}, classtopper[2] = {0};
	int i, j, k;
	
	for (i=0; i<2; i++){
		for(j=0; j<3; j++){
			for (k=0; k<3; k++) {
				printf("Enter marks for [%d][%d][%d]: ", i+1, j+1, k+1);
				scanf("%d", &marks[i][j][k]);
				total[i][j] += marks[i][j][k];

				
			}
		}
	}
	
	for (i=0; i<2; i++){
			printf("\n========== Marks for Class %d ==========\n", i+1);
		for(j=0; j<3; j++){
			printf("Student %d: ", j+1);
			for (k=0; k<3; k++) {
				printf("%d ", marks[i][j][k]);
			}
			printf("\t|\tTotal = %d\n", total[i][j]);
		}
	}
	
	for (i=0; i<2; i++){
		int topmarks = 0, topstudent =0;
		for(j=0; j<3; j++){
			for (k=0; k<3; k++) {
				if (total[i][j] > topmarks) {
					topmarks = total[i][j];
					topstudent = j;
				}
			}
		}
		classtop[i] = topmarks;
		classtopper[i] = topstudent;
		printf("\nTop Performer of Class %d: Student %d with %d marks", i+1, topstudent+1, topmarks);
	}
	
	int overalltop, overallclass, overallstudent;
	if (classtop[0] > classtop[1]) {
		overalltop = classtop[0];
		overallclass = 0;
		overallstudent = classtopper[0];
	}
	else {
		overalltop = classtop[1];
		overallclass = 1;
		overallstudent = classtopper[1];
	}
	
	printf("\nOverall Topper is from Class %d - student %d with %d marks", overallclass+1, overallstudent+1, overalltop);
	return 0;
}




