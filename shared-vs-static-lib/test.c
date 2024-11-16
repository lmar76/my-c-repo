#include <stdio.h>

#include "mylib.h"

int main()
{
  int num1 = 2;
  int num2 = 3;
  printf("Sum of %d and %d is: %d\n", num1, num2, sum(num1, num2));
  return 0;
}
