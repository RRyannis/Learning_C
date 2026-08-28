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

// #include <stdio.h>

// int main(void) {
//     int number, reversed, sum, digit1, digit2;
//     printf("Please enter an integer number with 2 digits.");
//     scanf("%d", &number);
//     if (number < 10 || number > 99) {
//         printf("Error. The number you entered doesn't have 2 digits.");
//         return 1;
//     }
//     digit1 = number / 10;
//     digit2 = number % 10;
//     reversed = digit2 * 10 + digit1;
//     sum = digit1 + digit2;
//     printf("The number reversed is %d\n", reversed);
//     printf("The sum of the number's digits is %d.", sum);
//     return 0;
// }

//Exam question 36, quick sort in C
// #include <stdio.h>

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = (low - 1);
//     for (int j = low; j < high; j++) {
//         if (arr[j] <= pivot) {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }

// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         int partitionIndex = partition(arr, low, high);
//         quickSort(arr, low, partitionIndex - 1);
//         quickSort(arr, partitionIndex + 1, high);
//     }
// }

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         printf("%d", arr[i]);
//         printf("\n");
//     }
// }

// int main(void) {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printf("Initial array: \n");
//     printArray(arr, n);
//     quickSort(arr, 0, n-1);
//     printf("Sorted array: \n");
//     printArray(arr, n);
//     return 0;
// }


//Exam question 10, groub B
// #include <stdio.h>

// int main (void) {

//     for (int i = 0; i < 10; i++) {
//         if (i == 5) {
//             break;        
//         }
//         printf("%d", i);
//     }
//     printf("\n");

//     for (int i = 0; i < 10; i++) {
//         if (i == 5) {
//             continue;
//         }
//         printf("%d", i);
//     }
//     return 0;
// }

//exam question 11, group B
// #include <stdio.h>

// int main(void) {
//     int num, sum = 0, count = 0;
//     printf("Enter integers. Enter 0 to exit.\n");
//     while(1) {
//         scanf("%d", &num);
//         if (num == 0) break;
//         sum += num;
//         count++;
//     }

//     if (count > 0) {
//         printf("Average of numbers entered: %.2f\n", (float)sum/count);
//     } else {
//         printf("No numbers entered.");
//     }

//     return 0;
// }

//exam question 12, group b

// #include <stdio.h>

// int main (void) {
//     int num1, num2, sum;

//     printf("Enter two integers.");
//     scanf("%d %d", &num1, &num2);

//     sum = num1 + num2;
//     printf("Sum(dec): %d\n", sum);
//     printf("Sum(oct): %o\n", sum);
//     printf("Sum(hex): %X\n", sum);
// }

//exam question 13, group b
// #include <stdio.h>

// float calculate(float a, float b) {
//     return (a + b)/2;
// }

// int main(void) {
    
//     float num1, num2;
    
//     printf("Enter two real numbers.");
//     scanf("%f %f", &num1, &num2);

//     float average = calculate(num1, num2);
//     printf("Their average is %f.", average);

//     return 0;
// }

//exam question 14, group b

// #include <stdio.h>

// int main(void) {
//     char name[50];
//     printf("What is your name?\n");
//     scanf("%s", name);
//     printf("Hello %s, welcome!", name);
// }

//exam question 15, group b

// #include <stdio.h>

// int main(void) {
//     printf("Fahrenheit\tCelsius\n");
//     for (int F = 0; F <= 200; F += 20) {
//         float C = 5.0 * (F - 32)/9;
//         printf("%d\t\t%.2f\n", F,C);
//     }
//     return 0;
// }

//stack in c
// C Program to demonstrate how to Implement a Stack
#include <stdio.h>
#include <stdbool.h>

// Define the maximim capacity of the stack
#define MAX_SIZE 100

// Define a structure for the stack
typedef struct {
    int arr[MAX_SIZE];  
    int top;        
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->top = -1;  
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;  
}

// Function to check if the stack is full
bool isFull(Stack *stack) {
    return stack->top >= MAX_SIZE - 1;  
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    int popped = stack->arr[stack->top];
    stack->top--;
    printf("Popped %d from the stack\n", popped);
    return popped;
}

// Function to peek the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);  

    push(&stack, 3);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 5);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 2);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 8);
    printf("Top element: %d\n", peek(&stack));

    while (!isEmpty(&stack)) {
        printf("Top element: %d\n", peek(&stack));
        printf("Popped element: %d\n", pop(&stack));
    }

    return 0;
}