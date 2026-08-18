//Exam Question 29, C code to calculate factorial

// #include <stdio.h>

// int main(void) {

//     int number;
//     unsigned long long result = 1 ;
//     printf("Please enter an integer number.");
//     scanf("%d", &number);
//     if(number < 0) {
//         printf("Number can't be negative");
//     } 
//     else {
//         for (int i = 1; i <= number; i++) {
//             result *= i;
//         }
//         printf("The factorial of %d is %llu.", number, result);
//     }
    
// }

//Exam question 31, recursion problem

// #include <stdio.h>

// int power(int a, int b);

// int main(void) {
//     int a = 3;
//     int b = 5;
//     int result = power(a, b);
//     printf("The result is %d.", result);
// }

// int power(int a, int b) {
    
//     if (b == 0) {
//         return 1;
//     }
//     return a * power(a, b - 1);

// }

//Exam question 32

// #include <stdio.h>
// #include <string.h>

// int main(void) { 
    
//     char salesmen[10][50];
//     int sales[10];
//     char salesmanBiggest[50] = "No one";
//     char salesmanSmallest[50] = "No one";
//     int sumOfSales = 0;
//     int biggestSale = 0;
//     int smallestSale = 1000000;

//     for(int i = 0; i <= 9; i++){
//         printf("Salesman name: ");
//         scanf("%s", salesmen[i]);
//         printf("Sales amount by that salesman: ");
//         scanf("%d", &sales[i]);
//         sumOfSales += sales[i];
//         if (sales[i] > biggestSale) {
//             biggestSale = sales[i];
//             strcpy(salesmanBiggest, salesmen[i]);
//         }
//         if (sales[i] < smallestSale) {
//             smallestSale = sales[i];
//             strcpy(salesmanSmallest, salesmen[i]);
//         }
//     }
//     int salesAverage = sumOfSales/10;
//     printf("The sales average was %d.", salesAverage);
//     printf("The name of the person with the most sales was %s.", salesmanBiggest);
//     printf("The name of the person with the fewest sales was %s.", salesmanSmallest);
    
//     return 0;
// }


//Exam question 35

#include <stdio.h>

int main(void) {
    int number, reversed, sum, digit1, digit2;
    printf("Please enter an integer number with 2 digits.");
    scanf("%d", &number);
    if (number < 10 || number > 99) {
        printf("Error. The number you entered doesn't have 2 digits.");
        return 1;
    }
    digit1 = number / 10;
    digit2 = number % 10;
    reversed = digit2 * 10 + digit1;
    sum = digit1 + digit2;
    printf("The number reversed is %d\n", reversed);
    printf("The sum of the number's digits is %d.", sum);
    return 0;
}