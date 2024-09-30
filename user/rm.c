#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define RED "\033[31m"
#define RESET "\033[0m"

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    fprintf(2, "Usage: rm files...\n");
    exit(1);
  }

  guy_mad();
  printf("%s", RED);
  printf("REMOVE IT !!\n");
  printf("%s", RESET);

  for(i = 1; i < argc; i++){
    if(unlink(argv[i]) < 0){
      fprintf(2, "rm: %s failed to delete\n", argv[i]);
      break;
    }
  }

  exit(0);
}
