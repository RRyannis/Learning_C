#include <stdio.h>

int main(void) {
    
    int num;
    unsigned long factorial = 1;
    
    printf("Enter a non negative number: \n");
    scanf("%d", &num);
    if (num < 0) {
        printf("Number cannot be negative.");
        return 0;
    }
    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }
    printf("The factorial of %d is %lu.", num, factorial);
    return 0;
}