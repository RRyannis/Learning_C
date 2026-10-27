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
int main(void) {
    int * pc, c;
    c = 21;
    pc = &c;
    printf("Address of c: %p \n", pc);
    printf("Address of c: %p \n", &c);
    printf("Value of c: %d \n", c);
    printf("Value of c: %d \n", *pc);


    int numbers[] = {5, 23, 675, 1231};
    for(int i = 0; i < 4; i++) {
        printf("%p \n", &numbers[i]);
    }

    int num = 21;
    printf("%zu \n", sizeof(num));

    int nums[] = {5, 23, 675, 1231};
    printf("%zu \n", sizeof(nums));

    int myNumbers[4] = {25, 50, 75, 100};
    int *p = myNumbers;  // points to myNumbers[0]

    printf("%d\n", *p);       // 25
    printf("%d\n", *(p + 1)); // 50
    printf("%d\n", *(p + 2)); // 75
    printf("%d\n", *(p + 3)); // 100

    int var = 42;
    int *ptr = &var;
    printf("Variable 'var' value: %d \n", var);
    printf("Variable 'var' address: %p \n", &var);
    printf("Pointer 'ptr' address (value of ptr): %p \n", ptr);
    printf("Value accessed via pointer (*ptr): %d", *ptr);

}
