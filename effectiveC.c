#include <stdio.h>

void swap(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}
int main(void) {
   int a = 6, b = 9;
   swap(&a, &b);
   printf("a = %d, b = %d \n", a, b);
   

    return 0;
}