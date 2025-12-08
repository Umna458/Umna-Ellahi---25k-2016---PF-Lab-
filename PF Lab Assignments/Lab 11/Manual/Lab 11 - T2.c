#include <stdio.h>
#include <string.h>

struct Route {
    char routeID[20];
    int distance;       
    float basePrice;    
    char roadType[20];  
    float totalCost;    
};

void calculateRouteCost(struct Route *r, int remainingDistance) {
    if (remainingDistance <= 0) 
        return;  

    float segmentCharge = r->basePrice;

    if (strcmp(r->roadType, "highway") == 0)
        segmentCharge += 5;
    else if (strcmp(r->roadType, "mountain") == 0)
        segmentCharge += 10;

    
    r->totalCost += segmentCharge;

    calculateRouteCost(r, remainingDistance - 10);
}

int main() {
    struct Route r1;

    printf("Enter Route ID: ");
    fgets(r1.routeID, sizeof(r1.routeID), stdin);
    r1.routeID[strcspn(r1.routeID, "\n")] = 0; 

    printf("Enter Distance (km): ");
    scanf("%d", &r1.distance);

    printf("Enter Base Price per 10 km: ");
    scanf("%f", &r1.basePrice);

    printf("Enter Road Type (normal/highway/mountain): ");
    scanf("%s", r1.roadType);

    r1.totalCost = 0; 

    calculateRouteCost(&r1, r1.distance);

    printf("\n=== Route Cost Summary ===\n");
    printf("Route ID: %s\n", r1.routeID);
    printf("Distance: %d km\n", r1.distance);
    printf("Road Type: %s\n", r1.roadType);
    printf("Total Delivery Cost: %.2f\n", r1.totalCost);

    return 0;
}

