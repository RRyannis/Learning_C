//εοππεπ ερώτηση 29, ομάδα α
// #include <stdio.h>

// int main(void) {
    
//     int num;
//     unsigned long factorial = 1;
    
//     printf("Enter a non negative number: \n");
//     scanf("%d", &num);
//     if (num < 0) {
//         printf("Number cannot be negative.");
//         return 0;
//     }
//     for (int i = 1; i <= num; i++) {
//         factorial *= i;
//     }
//     printf("The factorial of %d is %lu.", num, factorial);
//     return 0;
// }

//εοππεπ ερώτηση 31, ομάδα α
// #include <stdio.h>

// int power(int a, int b);

// int main(void) {

//     int num1, num2, result;
//     printf("Enter two integers: \n");
//     scanf("%d %d", &num1, &num2);
//     result = power(num1, num2);
//     printf("result: %d", result);
//     return 0;
// }

// int power(int a, int b) {

//     if (b == 0) {
//         return 1;
//     }

//     return a * power(a, b-1);
// }

//εοππεπ ερώτηση 36, ομάδα α

// #include <stdio.h>

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = (low - 1);
//     for (int j = low; j < high; j++){
//         if(arr[j] <= pivot) {   {5,16,1,32,21}; i = -1, low = 0, high = 4
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
    
//     int arr[] = {5,16,1,32,21};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printArray(arr, n);
//     quickSort(arr, 0, n -1);
//     printArray(arr, n);
    
//     return 0;
// }

//εοππεπ ερώτηση 38, ομάδα Α

// #include <stdio.h>

// int main(void) {
//     int arr[5][5], num;
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             printf("Enter an integer: \n");
//             scanf("%d", &num);
//             arr[i][j] = num;
//         }
//     }
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             printf("%d \n", arr[i][j]);
//         }
//     }
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             if (i == j) {
//                 printf("%d \n", arr[i][j]);
//             }
//         }
//     }

//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             if ((i + j) == 4) {
//                 printf("%d \n", arr[i][j]);
//             }
//         }
//     }

//     return 0;
// }


//εοππεπ ερώτηση 11, ομάδα Β

// #include <stdio.h>

// int main(void) {
//     int num, sum = 0, average, count = 0;
//     do {
//         printf("Enter integers, enter 0 to exit. \n");
//         scanf("%d", &num);
//         if (num == 0) break;
//         sum += num;
//         count++;
//     } while (1);
//     average = sum / count;
//     printf("Average is: %d \n", average);
//     return 0;
// }

//εοππεπ ερώτηση 12, ομάδα Β

// #include <stdio.h>

// int main(void) {
//     int num1, num2, sum = 0;
//     printf("Enter two numbers.\n");
//     scanf("%d %d", &num1, &num2);
//     sum = num1 + num2;
//     printf("decimal: %d \n", sum);
//     printf("octal: %o \n", sum);
//     printf("hexadecimal: %x \n", sum);
// }

//εοππεπ ερώτηση 13, ομάδα Β

// #include <stdio.h>

// float calculate(float a, float b) {
//     return (a + b)/2;
// }

// int main(void) {
//     float num1, num2, result;
//     printf("Enter two real numbers: \n");
//     scanf("%f %f", &num1, &num2);
//     result = calculate(num1, num2);
//     printf("Their average is %f.", result);
//     return 0;
// }

//εοππεπ ερώτηση 14, ομάδα Β
// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char name[50];
//     printf("What is your name?\n");
//     scanf("%s", name);
//     printf("Hello %s!", name);
//     return 0;
// }

//εοππεπ ερώτηση 15, ομάδα Β
// #include <stdio.h>

// int main(void) {
//     printf("Fahrenheit\tCelsius\n");
//     for (int F = 0; F <= 200; F += 20) {
//         float C = 5.0 * (F - 32)/9;
//         printf("%d\t\t%.2f\n", F,C);
//     }
//     return 0;
// }

//εοππεπ ερώτηση 37, ομάδα Α
// #include <stdio.h>

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void bubble_sort(int arr[], int n) {
//     int i, j, swapped;
//     for (i = 0; i < n - 1; i++) {
//         swapped = 0;
//         for (j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(&arr[j], &arr[j + 1]);
//                 swapped = 1;
//             }
//         }
//         if (!swapped) {
//             break;
//         }
//     }
// }

// void selection_sort(int arr[], int n) {
//     int i, j, min_idx;
//     for (i = 0; i < n - 1; i++) {
//         min_idx = i;
//         for (j = i + 1; j < n; j++) {
//             if (arr[j] < arr[min_idx]) {
//                 min_idx = j;
//             }
//         }
//         if (min_idx != i) {
//             swap(&arr[i], &arr[min_idx]);
//         }
//     }
// }

// void print_array(const char *label, const int arr[], int n) {
//     printf("%s: ", label);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main(void) {
//     int arr1[] = {64, 34, 25, 12, 22, 11, 90};
//     int arr2[] = {64, 34, 25, 12, 22, 11, 90};
//     int n1 = sizeof(arr1) / sizeof(arr1[0]);
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);

//     printf("--- Testing Bubble Sort ---\n");
//     print_array("Original", arr1, n1);
//     bubble_sort(arr1, n1);
//     print_array("Sorted  ", arr1, n1);

//     printf("\n--- Testing Selection Sort ---\n");
//     print_array("Original", arr2, n2);
//     selection_sort(arr2, n2);
//     print_array("Sorted  ", arr2, n2);

//     return 0;
// }
//εοππεπ ερώτηση 50 ομάδα Α
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX -1) {
        printf("Stack overflow!");
        return;
    }
    stack[++top] = value;
}

int pop(void) {
    if (top == -1) {
        printf("Stack underflow!");
        return -1;
    }
    return stack[top--];
}
int main(void) {
    
    push(10);
    push(20);
    push(30);

    printf("%d \n", pop());
    printf("%d \n", pop());
}