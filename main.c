//bitwise exercise, equivalent of 6 *  13
#include <stdio.h>

int main(void) {
  int num1 = 6;
  int num2 = 13;
  int shift = 0;

  while (num2 > 1) {
    num2 = num2 / 2;
    shift++;
  }

  printf("%d << %d is %d \n", num1, shift, num1 << shift);
}