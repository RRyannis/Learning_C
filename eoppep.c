//Exam Question 29, C code to calculate factorial

#include <stdio.h>

int main(void) {

    int number;
    unsigned long long result = 1 ;
    printf("Please enter an integer number.");
    scanf("%d", &number);
    if(number < 0) {
        printf("Number can't be negative");
    } 
    else {
        for (int i = 1; i <= number; i++) {
            result *= i;
        }
        printf("The factorial of %d is %llu.", number, result);
    }
    
}