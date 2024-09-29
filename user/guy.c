#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void clearScreen() {
	printf("\033[H\033[J");
}

void printGuy(int pos) {
	for (int j = 0; j < pos; j++) {
        	printf(" ");
	}

	printf("   O   \n");
    	
	for (int j = 0; j < pos; j++) {
                printf(" ");
        }
	printf("  /|\\  \n");
    	
	for (int j = 0; j < pos; j++) {
                printf(" ");
        }
	printf("  / \\  \n");
}

void guyRun() {
	for (int i = 0; i < 30; i++) {
        	clearScreen();
       		printGuy(i);
        	sleep(5);
    	}
}

int main () {

	guyRun();

	return 0;
}
