#include "user/user.h"
#include "kernel/types.h"
#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"


void clear_screen() {
	printf("\033[H\033[J");
}

void print_guy() {
	char *buffer = (char *)malloc(128*20);
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
	//initializing final buffer and buffer for pos number of spaces
	char *buffer = (char *)malloc((pos*3 + 30)*sizeof(char));
	char *spaces = (char *)malloc(pos*sizeof(char));
	//Creating body
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
	//Coping body with pos number of spaces into buffer
	memcpy(buffer + (pos * 2) + strlen(head), torso, strlen(torso) + 1);
	memcpy(buffer + (pos * 2) + strlen(head) + strlen(torso), spaces, strlen(spaces) + 1);
	memcpy(buffer + (pos * 3) + strlen(head) + strlen(torso), legs, strlen(legs) + 1);
	//Freeing everything
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
		clear_screen();
		if (i % 2 == 0) {
			print_guy_L();
		} else {
			print_guy_R();
		}
		sleep_ms(10);
	}
	clear_screen();
	print_guy();
	printf("RAHHHHHHHHHH!!\n");
	printf("%s", RESET);
}

void guy_move_head() {
        for (int i = 0; i < 15; i++) {
                clear_screen();
                if (i % 2 == 0) {
                        print_guy_L();
                } else {
                        print_guy_R();
                }
                sleep_ms(10);
        }
        clear_screen();
        print_guy();
}



void guy_run() {
	for (int i = 0; i < 20; i++) {
        	clear_screen();
       		print_guy_run(i);
		sleep_ms(10);
    	}
	for (int i = 20; i >0; i--) {
                clear_screen();
                print_guy_run(i);
                sleep_ms(10);
        }
	printf("OS ROCKS!!\n");
} 

void guy_celebrate() {
	clear_screen();
        print_guy_U();
        printf("%s", GREEN);
        for (int i = 0; i < 15; i++) {
                clear_screen();
                if (i % 2 == 0) {
                        print_guy_U();
                } else {
                        print_guy();
                }
                sleep_ms(10);
        }
        clear_screen();
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

void print_mes(char* str) {
	print_guy();
	printf("     ^");
	printf("   /   \\n");
	printf("  |     | \n");
	printf("  |     | \n");
	printf("%s", str);
	free(str);
}

void guy_celebrate_intro() {
	clear_screen();
	print_guy_U();
	printf("%s", GREEN);
        for (int i = 0; i < 15; i++) {
                clear_screen();
                if (i % 2 == 0) {
                        print_guy_U();
                } else {
                        print_guy();
                }
                sleep_ms(10);
        }
        clear_screen();
	sleep(1);
	guy_run();
	guy_move_head();
	printf("WELCOME TO FogOS !! Type \"guy info\" to see more of me.\n");
        printf("%s", RESET);
}
