#include <stdio.h>
//creating a struct node
struct node {
    int value;
    struct node *next;
};

int main (void) {
    struct node test;
    test.value = 0;

    struct node test2;
    test2.value = 1;

    test.next = &test2;

    printf("%d \n", test.value);
    printf("%d \n", test.next->value);
    printf("%d \n", test2.value);



}



// //listing 2-6 and exercise 2-1
// static unsigned int counter = 0;

// void increment(void) {
//     // static unsigned int counter = 0;
//     counter++;
//     //printf("%d ", counter);
// }
// unsigned int retrieve(void) {
//     return counter;
// }
// int main(void) {
//     for (int i = 0; i < 5; i++) {
//     increment();
//     }
//     printf("\ncounter is currently %u\n", retrieve());
//     return 0;
// }
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