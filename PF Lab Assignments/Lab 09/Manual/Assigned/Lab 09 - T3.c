
#include <stdio.h>
#include <stdlib.h>

void init_flights(int *flights[]);
void book_seat(int *flight, int capacity, int seat);
void cancel_seat(int *flight, int capacity, int seat);
int count_occupied(int *flight, int capacity);

int main() {
    int capacities[3] = {5, 7, 9};
    int *flights[3];
    int num = 3;
    int f, seat, i;
    int choice;
    
    init_flights(flights);

    while (1) {
        printf("\n1.Book\n2.Cancel\n3.Show Totals\n4.Exit\nChoose: ");
        if (scanf("%d", &choice) != 1)
			 break;
			 
        if (choice == 4) {
		
        	printf("Exiting program...");
			break;
		}
		
        if (choice == 1) {
            printf("Flight (1-3): "); 
			scanf("%d", &f);
            printf("Seat number: "); 
			scanf("%d", &seat);
			
            book_seat(flights[f-1], capacities[f-1], seat);
            
        } else if (choice == 2) {
            printf("Flight (1-3): "); 
			scanf("%d", &f);
            printf("Seat number: "); 
			scanf("%d", &seat);
			
            cancel_seat(flights[f-1], capacities[f-1], seat);
            
        } else if (choice == 3) {
            for (i = 0; i < num; ++i) {
                printf("Flight %d occupied seats: %d / %d\n", i+1, count_occupied(flights[i], capacities[i]), capacities[i]);
            }
        } else printf("Invalid option.\n");
    }

    for (i = 0; i < num; ++i) 
		free(flights[i]);
    return 0;
}

void init_flights(int *flights[]) {
    static int flight1[5] = {0}; 
    static int flight2[7] = {0};
    static int flight3[9] = {0}; 

    flights[0] = flight1;
    flights[1] = flight2;
    flights[2] = flight3;
}

void book_seat(int *flight, int capacity, int seat) {
	
    if (seat < 1 || seat > capacity) {
        printf("Invalid seat number.\n");
        return;
    }
    if (flight[seat - 1] == 1) 
		printf("Seat already booked.\n");
    else {
        flight[seat - 1] = 1;
        printf("Seat %d booked.\n", seat);
    }
}

void cancel_seat(int *flight, int capacity, int seat) {
	
    if (seat < 1 || seat > capacity) {
        printf("Invalid seat number.\n");
        return;
    }
    if (flight[seat - 1] == 0) 
		printf("Seat already free.\n");
    else {
        flight[seat - 1] = 0;
        printf("Seat %d cancelled.\n", seat);
    }
}

int count_occupied(int *flight, int capacity) {
    int count = 0, i;
    
    for (i = 0; i < capacity; ++i) 
		count += flight[i];
    return count;
}



