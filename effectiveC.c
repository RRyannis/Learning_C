//compile with gcc -Wall -Wextra -std=c11 -g -O0 effectiveC.c -o efC
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap_any(void *a, void *b, size_t sz) {
    unsigned char temp[sz];
    memcpy(temp, a, sz);
    memcpy(a, b, sz);
    memcpy(b, temp, sz);
}
int main(void) {
    int    xi = 10,  yi = 20;
    double xd = 1.5, yd = 2.5;
    char   xs[] = "hello", ys[] = "world";

    swap_any(&xi, &yi, sizeof(int));
    swap_any(&xd, &yd, sizeof(double));
    swap_any(&xs, &ys, sizeof(xs));

    printf("xi=%d yi=%d\n", xi, yi);    // xi=20 yi=10
    printf("xd=%f yd=%f\n", xd, yd);    // xd=2.500000 yd=1.500000
    printf("xs=%s ys=%s\n", xs, ys);    // xs=world ys=hello
    return 0;
}
