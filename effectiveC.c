#include <stdio.h>
#include <stdlib.h>   //for malloc() and free()

int main(void)
{
    int n = 5;  // how many integers (could be decided at runtime!)

    // Asking the system for enough memory to hold 5 ints.
    // malloc returns a pointer to the start of that memory block.
    int *numbers = malloc(n * sizeof(int));

    //ALWAYS check whether the allocation succeeded.
    //If malloc fails (e.g., out of memory), it returns NULL.
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //Use memory like a regular array.
    for (int i = 0; i < n; i++) {
        numbers[i] = i * 10;
    }

    //Print the values back out.
    for (int i = 0; i < n; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    // Give the memory back when you're done with it.
    free(numbers);
    numbers = NULL;  // good habit: avoids accidentally reusing a freed pointer

    return 0;
}
// //creating a struct node
// struct node {
//     int value;
//     struct node *next;
// };

// int main (void) {
//     struct node test;
//     test.value = 0;

//     struct node test2;
//     test2.value = 1;

//     test.next = &test2;

//     printf("%d \n", test.value);
//     printf("%d \n", test.next->value);
//     printf("%d \n", test2.value);



// }



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