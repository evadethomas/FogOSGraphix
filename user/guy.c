#include "user/user.h"
#include "kernel/types.h"

int main (int argc, char *argv[]) {
	if (argc == 1) {
                print_guy();
        } else if (strcmp(argv[1], "run") == 0) {
                guy_run();
        } else if ((strcmp(argv[1], "gets") == 0) && (strcmp(argv[2], "mad") == 0)) {
                guy_mad();
        } else if (strcmp(argv[1], "info") == 0) {
                guy_info();
        } else {
		guy_mad();
		printf("Mistyped, try again");
	}
        return 0;
}
