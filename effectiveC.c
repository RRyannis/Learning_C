#include <stdio.h>
//listing 2-6 and exercise 2-1
static unsigned int counter = 0;

void increment(void) {
    // static unsigned int counter = 0;
    counter++;
    //printf("%d ", counter);
}
unsigned int retrieve(void) {
    return counter;
}
int main(void) {
    for (int i = 0; i < 5; i++) {
    increment();
    }
    printf("\ncounter is currently %u\n", retrieve());
    return 0;
}
// void swap(int *pa, int *pb) {
//     int temp = *pa;
//     *pa = *pb;
//     *pb = temp;
// }
// int main(void) {
//    int a = 6, b = 9;
//    swap(&a, &b);
//    printf("a = %d, b = %d \n", a, b);
   

//     return 0;
// }