#include <stdio.h>
#include <math.h>

struct File {
    char filename[50];
    float ogSize;        
    float reduction_rate; 
};

float fileSize(struct File *f, int n) {
    if (n == 0) {
        return f->ogSize; 
    } else {
        float initialSize = fileSize(f, n - 1);
        float reduced = ceil(initialSize * f->reduction_rate);
        float updatedSize = initialSize - reduced;
        if (updatedSize < 0) updatedSize = 0; 
        return updatedSize;
    }
}

int main() {
    struct File f1;
    int k;

    printf("Enter File Name: ");
    scanf("%s", f1.filename);

    printf("Enter Original File Size (MB): ");
    scanf("%f", &f1.ogSize);

    printf("Enter Reduction Rate per Pass (e.g., 0.10 for 10%%): ");
    scanf("%f", &f1.reduction_rate);

    printf("Enter Number of Compression Passes: ");
    scanf("%d", &k);

    float finalSize = fileSize(&f1, k);

    printf("\n=== File Compression Estimator ===\n");
    printf("File Name: %s\n", f1.filename);
    printf("Original Size: %.2f MB\n", f1.ogSize);
    printf("Reduction Rate: %.2f%% per pass\n", f1.reduction_rate * 100);
    printf("Compression Passes: %d\n", k);
    printf("Estimated Size After %d Passes: %.2f MB\n", k, finalSize);

    return 0;
}





