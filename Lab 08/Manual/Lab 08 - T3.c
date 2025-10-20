#include <stdio.h>

int main() {
    int i, j;
    int avg0, avg1;
    int sum = 0, sum1 = 0;
    int pixel[5][5], pixel1[5][5];
    
    // Input Original Matrix
    printf("Enter image pixel intensity values (0-255)\n");
    for (i = 0; i < 5; i++) {
        printf("  Row %d\n", i + 1);
        for (j = 0; j < 5; j++) {
            printf("Pixel %d: ", j + 1);
            scanf("%d", &pixel[i][j]);
            sum += pixel[i][j];
        }
    }
    
    // Display Original Image Matrix
    printf("\nOriginal Image Matrix\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", pixel[i][j]);
        }
        printf("\n");
    }
    
    avg0 = sum / (5 * 5);
    printf("\nAverage of Original Image Pixel Intensity is %d\n", avg0);
    
    // Create Sharpened Image Matrix
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            pixel1[i][j] = pixel[i][j] * 2;
            
            if (pixel1[i][j] > 255)
                pixel1[i][j] = 255;
            
            sum1 += pixel1[i][j];
        }
    }
    
    // Display Sharpened Image Matrix
    printf("\nSharpened Image Matrix\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", pixel1[i][j]);
        }
        printf("\n");
    }
    
    avg1 = sum1 / (5 * 5);
    printf("\nAverage of Sharpened Image Pixel Intensity is %d\n", avg1);
    
    return 0;
}


