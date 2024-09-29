#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define RED "\033[31m"
#define RESET "\033[0m"

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

void print_guy() {
	char *buffer = (char *)malloc(128*20);
	
	strcpy(buffer, "   O   \n  /|\\  \n  / \\  \n\0");
	
	printf(buffer);
	
	free(buffer);
}


void print_guy_run(int pos) {
	char *buffer = (char *)malloc((pos*3 + 30)*sizeof(char));
	char *spaces = (char *)malloc(pos*sizeof(char));
	
	for (int i = 0; i < pos; i++) {
        	spaces[i] = ' ';
    	}


	char *head = (char *)malloc(10 * sizeof(char));
	strcpy(head, "   O   \n");

	memcpy(buffer, spaces, strlen(spaces) +1);
	memcpy(buffer + pos, head, strlen(head) + 1);
	memcpy(buffer + pos + strlen(head), spaces, strlen(spaces) + 1);
	

	char *torso = (char *)malloc(10 * sizeof(char));
        strcpy(torso, "  /|\\  \n");

	char *legs = (char *)malloc(10 * sizeof(char));
        strcpy(legs, "  / \\  \n");

	memcpy(buffer + (pos * 2) + strlen(head), torso, strlen(torso) + 1);
	memcpy(buffer + (pos * 2) + strlen(head) + strlen(torso), spaces, strlen(spaces) + 1);
	memcpy(buffer + (pos * 3) + strlen(head) + strlen(torso), legs, strlen(legs) + 1);
       	
	printf(buffer);

	free(buffer);
	free(head);
	free(torso);
	free(legs);
	free(spaces);
	
}

void guy_color() {
	printf("%s", RED);
	print_guy();
	printf("%s", RESET);
}



void guy_run() {
	for (int i = 0; i < 30; i++) {
        	clearScreen();
       		print_guy_run(i);
		sleep_ms(10);
    	}
	for (int i = 30; i >0; i--) {
                clearScreen();
                print_guy_run(i);
                sleep_ms(10);
        }
}

int main (int argc, char *argv[]) {

	if (argc == 1) {
		print_guy();
	} else if (strcmp(argv[1], "run") == 0) {
		guy_run();
	} else {
		printf("Fail");
	}

	guy_color();
	return 0;
}
