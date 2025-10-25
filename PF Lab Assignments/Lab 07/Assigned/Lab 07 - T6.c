#include<stdio.h>
int main () {
	int posts[10] = {2,5,9,11,8,6,13,10,4,8};
	int highest = 0, streak, highest_day, i, total;
	float avg;
	
	printf("======= Weekly Activity Summary ======\n\n");
	highest = posts[0];
	for(i = 0; i<10; i++) {
		printf("Day: %d\t\tPosts: %d\n", i+1, posts[i]);
		total += posts[i];
		if (posts[i] > highest) {
			highest = posts[i];
			highest_day = i+1;
		}
	}
	
	avg = total/10;	
		
	for (i = 0; i < 8; i++) {
		if (posts[i] < posts[i+1] && posts[i+1] < posts[i+2]) {
			printf("Streak Detected: Days %d, %d, %d\n", i+1, i+2, i+3);
		}
	}
	
	printf("Average Daily Activity: %.2f", avg);
	return 0;
}



