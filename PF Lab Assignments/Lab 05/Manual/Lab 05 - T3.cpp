#include <stdio.h>
#include <math.h>
int main() {
	int vul_score, mal_score;
	int risk = 0;
	
	printf("Enter system vulnerability score (1-10): ");
	scanf("%d", &vul_score);
	
	printf("Enter malware strength (1-10): ");
	scanf("%d", &mal_score);
	
	risk = pow(vul_score,2) + (pow(mal_score,2))/20;
	
	(risk > 5) ? printf("High Infection Probability"): printf("Low Infection Probability");	
	
return 0;
}




