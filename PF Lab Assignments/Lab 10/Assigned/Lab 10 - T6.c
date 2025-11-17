#include<stdio.h>
#include<string.h>

int main () {
	char book[50];
	int i, found = 0;
	char titles[10][50] = {
	"C Programming","Data Science","Algorithms",
    "Networking","Database","Operating Systems",
    "Python Crash Course","Java Basics","Discrete Math",
    "Computer Architecture"};

	
	printf("=== LIBRARY BOOK SEARCH ===\n");
	printf("Enter book to be searched: ");
	scanf(" %[^\n]", book);
	
	for (i=0; i<10; i++) {
		if(strcmp(book, titles[i]) == 0) {
		printf("\nBook Found.\n");
		printf("Title: %s\n", titles[i]);
		found = 1;
		break;	}
	else if (found == 0)
		printf("Book Not Found"); }
	
	
	return 0;
}




