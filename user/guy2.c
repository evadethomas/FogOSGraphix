#include "user/user.h"
#include "kernel/types.h"
#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"


void clearScreen() {
	printf("\033[H\033[J");
}

void print_guy() {
	char *buffer = (char *)malloc(128*20);
//	char *buffer = (char *)malloc(1);
	strcpy(buffer, "   O   \n  /|\\  \n  / \\  \n\0");
	
	printf(buffer);
	
	free(buffer);
}

void print_guy_U() {
        char *buffer = (char *)malloc(128*20);

        strcpy(buffer, "\n   O   \n  /|\\  \n  / \\  \n\0");

        printf(buffer);

        free(buffer);
}

void print_guy_L() {
        char *buffer = (char *)malloc(128*20);

        strcpy(buffer, "  O   \n  /|\\  \n  / \\  \n\0");

        printf(buffer);

        free(buffer);
}

void print_guy_R() {
        char *buffer = (char *)malloc(128*20);

        strcpy(buffer, "    O  \n  /|\\  \n  / \\  \n\0");

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

void guy_mad() {
	printf("%s", RED);
	for (int i = 0; i < 15; i++) {
		clearScreen();
		if (i % 2 == 0) {
			print_guy_L();
		} else {
			print_guy_R();
		}
		sleep_ms(10);
	}
	clearScreen();
	print_guy();
	printf("%s", RESET);
}

void guy_move_head() {
        for (int i = 0; i < 15; i++) {
                clearScreen();
                if (i % 2 == 0) {
                        print_guy_L();
                } else {
                        print_guy_R();
                }
                sleep_ms(10);
        }
        clearScreen();
        print_guy();
}



void guy_run() {
	for (int i = 0; i < 20; i++) {
        	clearScreen();
       		print_guy_run(i);
		sleep_ms(10);
    	}
	for (int i = 20; i >0; i--) {
                clearScreen();
                print_guy_run(i);
                sleep_ms(10);
        }
} 

void guy_celebrate() {
	clearScreen();
        print_guy_U();
        printf("%s", GREEN);
        for (int i = 0; i < 15; i++) {
                clearScreen();
                if (i % 2 == 0) {
                        print_guy_U();
                } else {
                        print_guy();
                }
                sleep_ms(10);
        }
        clearScreen();
	print_guy();
        printf("%s", RESET);
}

void guy_info() {
	print_guy();
	guy_celebrate();
	printf("%s", GREEN);
	printf("I'm your OS buddy! As you interact with the OS, you can type \n\"guy celebrate\", \"guy gets mad\", or \"guy run\" \nas you get bored/frustrated.\nYou will also find me scattered across various functions in the OS that call on the \"guy\" library !!\nTry calling ls to see an example.\n");
	printf("%s", RESET);
}

void print_message(char* mes) {
	print_guy();
	printf("     ^");
	printf("   /   \\n");
	printf("  |     | \n");
	printf("  |     | \n");
	printf("%s", mes);
}

void guy_celebrate_intro() {
	clearScreen();
	print_guy_U();
	printf("%s", GREEN);
        for (int i = 0; i < 15; i++) {
                clearScreen();
                if (i % 2 == 0) {
                        print_guy_U();
                } else {
                        print_guy();
                }
                sleep_ms(10);
        }
        clearScreen();
	sleep(1);
	guy_run();
	guy_move_head();
	printf("WELCOME TO FogOS !! Type \"guy info\" to see more of me.\n");

        printf("%s", RESET);
}
