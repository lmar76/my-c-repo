#include <stdio.h>
#include <stdlib.h>

#include "mylib.c"

#define USAGE "Usage:\n\t%s first-number second-number\n"

int main(int argc, char* argv[])
{
  if (argc < 3)
  {
    printf(USAGE, argv[0]);
    exit(EXIT_FAILURE);
  }

  printf("%d\n", sum(atoi(argv[1]), atoi(argv[2])));

  exit(EXIT_SUCCESS);
}
