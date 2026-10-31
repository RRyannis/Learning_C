//compile with gcc -Wall -Wextra -std=c11 -g -O0 effectiveC.c -o efC
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// void swap_any(void *a, void *b, size_t sz) {
//     unsigned char temp[sz];
//     memcpy(temp, a, sz);
//     memcpy(a, b, sz);
//     memcpy(b, temp, sz);
// }
// int main(void) {
//     int    xi = 10,  yi = 20;
//     double xd = 1.5, yd = 2.5;
//     char   xs[] = "hello", ys[] = "world";

//     swap_any(&xi, &yi, sizeof(int));
//     swap_any(&xd, &yd, sizeof(double));
//     swap_any(&xs, &ys, sizeof(xs));

//     printf("xi=%d yi=%d\n", xi, yi);    // xi=20 yi=10
//     printf("xd=%f yd=%f\n", xd, yd);    // xd=2.500000 yd=1.500000
//     printf("xs=%s ys=%s\n", xs, ys);    // xs=world ys=hello
//     return 0;
// }

// struct S {
// int i; double d; char c;
// };
// int main(void) {
// unsigned char bad_buff[sizeof(struct S)];
// _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];
// struct S *bad_s_ptr = (struct S *)bad_buff; // wrong pointer alignment
// struct S *good_s_ptr = (struct S *)good_buff; // correct pointer alignment
// }

//working with pointers
// int main(void) {
//     int * pc, c;
//     c = 21;
//     pc = &c;
//     printf("Address of c: %p \n", pc);
//     printf("Address of c: %p \n", &c);
//     printf("Value of c: %d \n", c);
//     printf("Value of c: %d \n", *pc);


//     int numbers[] = {5, 23, 675, 1231};
//     for(int i = 0; i < 4; i++) {
//         printf("%p \n", &numbers[i]);
//     }

//     int num = 21;
//     printf("%zu \n", sizeof(num));

//     int nums[] = {5, 23, 675, 1231};
//     printf("%zu \n", sizeof(nums));

//     int myNumbers[4] = {25, 50, 75, 100};
//     int *p = myNumbers;  // points to myNumbers[0]

//     printf("%d\n", *p);       // 25
//     printf("%d\n", *(p + 1)); // 50
//     printf("%d\n", *(p + 2)); // 75
//     printf("%d\n", *(p + 3)); // 100

//     int var = 42;
//     int *ptr = &var;
//     printf("Variable 'var' value: %d \n", var);
//     printf("Variable 'var' address: %p \n", &var);
//     printf("Pointer 'ptr' address (value of ptr): %p \n", ptr);
//     printf("Value accessed via pointer (*ptr): %d", *ptr);

// }

//effective c chapter 2 page 34 exercise 2

// #include <stdio.h>

// #define NUM_FUNCS 3

// void printOne(void) { printf("1\n"); }
// void printTwo(void) { printf("2\n"); }
// void printThree(void) { printf("3\n"); }

// void (*ptr[NUM_FUNCS])(void) = {printOne, printTwo, printThree};

// void acceptNum(int num) {
//     if (num < 0 || num >= NUM_FUNCS) {
//         printf("Enter a number from 0 to %d\n", NUM_FUNCS - 1);
//         return;
//     }
//     ptr[num]();
// }

// int main(void) {
//     acceptNum(1);
//     acceptNum(3);
//     acceptNum(-1);
//     acceptNum(0);
//     return 0;
// }


//pointers and text 2a
#include <stdio.h>


int count_occurrences(const char *s, char ch) {
    int count = 0;
    while(*s != '\0'){
        if(*s == ch) count++;
        s++;
    }
    return count;
}

//alternative
// int count_occurrences(const char *s, char ch) {
//     int count = 0;
//     for (; *s; s++) {
//         if (*s == ch) {
//             count++;
//         }
//     }
//     return count;
// }

int main(void) {
    
    //method 1
    //char greeting[] = "Hello";
    // int i = 0;
    // while(greeting[i] != '\0') {
    //     printf("%c\n", greeting[i]);
    //     i++;
    // }

    //method 2
    // const char *s = "mississippi";
    // char t = 's';
    // int count = 0;
    // while(*s != '\0') {
    //     if (*s == t) count++;
    //     printf("%c\n", *s);
    //     s++;
    // }
    // printf("%d\n", count);
    const char *text = "mississippi";
    printf("%d\n", count_occurrences(text, 's'));   // 4
    printf("%d\n", count_occurrences(text, 'z'));   // 0
    printf("%d\n", count_occurrences("", 'a'));    // 0
    return 0;
    
    
    
}

//2b tba: write the two functions
/*
 * ============================================================================
 * LESSON 2b — Arrays vs. pointers
 * ============================================================================
 *
 * CONCEPT
 * -------
 * Three real differences between `int arr[5]` and `int *p = arr`:
 *
 *   1. sizeof gives different answers:
 *        sizeof(arr)  → 20  (5 ints × 4 bytes)
 *        sizeof(p)    → 8   (the pointer itself, on 64-bit)
 *
 *   2. arr is NOT assignable; p IS:
 *        arr = x;    // compile error
 *        p   = x;    // fine
 *
 *   3. When passed to a function, an array "decays" into a pointer
 *      to its first element. Inside the function, it's just a pointer —
 *      the array's size information is LOST.
 *      That's why every array-taking function needs a separate size_t n.
 *
 * ============================================================================
 * EXERCISE
 * ============================================================================
 *
 * Write two functions and a main that calls them:
 */

#include <stdio.h>
#include <stddef.h>

/* TODO: print sizeof(a), sizeof(a[0]), and n */
void take_array(int a[], size_t n) {
    /* ... */
}

/* TODO: print sizeof(p), sizeof(p[0]), and n */
void take_ptr(int *p, size_t n) {
    /* ... */
}

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("sizeof(arr)    = %zu\n", sizeof(arr));
    printf("sizeof(p)      = %zu\n", sizeof(p));
    printf("sizeof(arr[0]) = %zu\n", sizeof(arr[0]));
    printf("&arr    = %p\n", (void*)&arr);
    printf("&arr[0] = %p\n", (void*)&arr[0]);

    take_array(arr, 5);
    take_ptr(p, 5);

    return 0;
}

/*
 * ============================================================================
 * NOTES ON THE FORMAT SPECIFIERS (so you understand why)
 * ============================================================================
 *   %zu  — correct format for size_t (what sizeof returns)
 *   %p   — for printing pointers; expects void*, hence the casts
 *
 * ============================================================================
 * COMPILE & RUN
 * ============================================================================
 *   gcc -Wall -Wextra -std=c11 -g -O0 effectiveC.c -o efC
 *   ./efC
 *
 * ============================================================================
 * BRING BACK
 * ============================================================================
 *   1. Your source code (both functions + main).
 *   2. The exact output of running it.
 *   3. One-paragraph answer in your own words:
 *
 *        "When you pass an array to a function, what type does the function
 *         actually receive? What information is lost in that transition,
 *         and why does this make C arrays 'second-class' compared to
 *         Java arrays?"
 *
 *   4. BONUS (optional): in main, do &arr and &arr[0] print the same
 *      address? If yes, are they really 'the same thing'? What's actually
 *      different about them? (Hint: think about their TYPES, not their
 *      numeric value.)
 *
 * ============================================================================
 */

void take_array(int a[], size_t n);
void take_ptr(int *p, size_t n);
int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;

    // Print these in main:
    printf("sizeof(arr) = %zu\n", sizeof(arr));
    printf("sizeof(p)   = %zu\n", sizeof(p));
    printf("sizeof(arr[0]) = %zu\n", sizeof(arr[0]));
    printf("&arr   = %p\n", (void*)&arr);
    printf("&arr[0] = %p\n", (void*)&arr[0]);

    take_array(arr, 5);
    take_ptr(p, 5);

    return 0;
}
