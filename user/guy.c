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

void print_guy(int pos) {
	char *buffer = (char *)malloc(128*pos*20);
	strcpy(buffer, "   O   \n");
	printf(buffer);
	strcpy
	free(buffer);
}



void guyRun() {
	for (int i = 0; i < 30; i++) {
        	clearScreen();
       		print_guy(i);
        	sleep(0.5);
    	}
}

int main () {

	guyRun();

	return 0;
}
