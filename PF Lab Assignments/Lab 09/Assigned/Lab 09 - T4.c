#include <stdio.h>
float average_rain(float *arr, int n);
int max_rainday(float *arr, int n);

int main() {
    float rain[7];
    int aboveavg = 0;
    int i;
    
    printf("Enter rainfall for 7 days (mm):\n");
    for (i = 0; i < 7; ++i) 
		scanf("%f", &rain[i]);

    float avg = average_rain(rain, 7);
    int maxday = max_rainday(rain, 7);

    for (i = 0; i < 7; ++i) {
    	if (*(rain + i) > avg)
			++aboveavg;
	}

    printf("Average rainfall: %.2f mm\n", avg);
    printf("Maximum rainfall on day %d: %.2f mm\n", maxday + 1, *(rain + maxday));
    
	if (aboveavg > 3) 
		printf("Rainy Week\n");
    else
		printf("Normal Week\n");
		
    return 0;
}
float average_rain(float *arr, int n) {
    float sum = 0;
    int i;
    
    for (i = 0; i < n; ++i) 
		sum += *(arr + i);
		
    return sum / n;
}

int max_rainday(float *arr, int n) {
    int index = 0;
    int i;
    
    for (i = 1; i < n; ++i) {
        if (*(arr + i) > *(arr + index)) index = i;
    }
    return index; 
}



