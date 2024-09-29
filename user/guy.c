#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void printGuy() {
	printf("   O   \n");
    	printf("  /|\\  \n");
    	printf("  / \\  \n");
}

int main () {
	printGuy();
	return 0;
}
