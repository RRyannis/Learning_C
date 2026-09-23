//problem 20 valid parentheses
#include <stdio.h>
#include <string.h>
bool isValid(char* s)
{
    int n = strlen(s);

    char stack[n];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack[++top] = s[i];
        }
        else
        {
            if (top == -1)
                return false;

            char opening = stack[top--];

            if (s[i] == ')' && opening != '(')
                return false;

            if (s[i] == ']' && opening != '[')
                return false;

            if (s[i] == '}' && opening != '{')
                return false;
        }
    }

    return top == -1;
}
int main(void) {
    
    
     char* tests[] = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "(((",
        ")))",
        "",
        "{[()]}"
    };

    int numberOfTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numberOfTests; i++) {

        printf("\"%s\" -> ", tests[i]);

        if (isValid(tests[i])) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }

    return 0;
}
//problem 53 maximum subarray
// #include <stdio.h>
// int maxSubArray(int* nums, int numsSize) {
//     int currentSum = 0;
//     int bsf = nums[0];

//     for (int i = 0; i < numsSize; i++) {
//         if (currentSum + nums[i] < nums[i]) {
//             currentSum = nums[i];
//         } else {
//             currentSum += nums[i];
//         }
//         if (currentSum > bsf){
//             bsf = currentSum;
//         }
//     }
//     return bsf;
// }
// int main(void) {
//     int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
//     int size = sizeof(nums)/sizeof(nums[0]);
//     int result = maxSubArray(nums, size);
//     printf("%d \n", result);

//     return 0;
// }
//problem 283 single move zeroes
// #include <stdio.h>
    
// void moveZeroes(int* nums, int numsSize) {

//     int writeIndex = 0;
//     for (int readIndex = 0; readIndex < numsSize; readIndex++) {
//         if (nums[readIndex] != 0) {
//             nums[writeIndex] = nums[readIndex];
//             writeIndex++;
//         }
//     }
//     for (int i = writeIndex; i < numsSize; i ++) {
//         nums[i] = 0;
//     }

// }
// int main(void) {
//     int nums[] = {0,4,6,2,0,4,0};
//     int size = sizeof(nums)/sizeof(nums[0]);
//     moveZeroes(nums, size);
//     for (int i = 0; i < size; i++) {
//         printf("%d ", nums[i]);
//     }
//     return 0;
// }

// //problem 136 single number
// #include <stdio.h>
// int singleNumber(int* nums, int numsSize){
//     int result = 0;
//     for (int i = 0; i <= numsSize-1; i++) {
//         result ^= nums[i];
//         printf("%d \n", result);
//     }
//     return result;
// }

// int main(void) {
//     int nums[] = {4, 1, 2, 1, 2};
//     int lengthOfNums = sizeof(nums)/sizeof(nums[0]);
//     printf("%d \n", singleNumber(nums, lengthOfNums));
    
    
//     return 0;
// }

//problem 58 length of last string
// #include <stdio.h>
// #include <string.h>

// int lengthOfLastWord(char* s) {
//     int length = 0;
//     for (int i = strlen(s) - 1; i >=0; i--){
//         if(s[i] == ' ' && length == 0){
//             continue;
//         } else if (s[i] == ' ' && length > 0) {
//             return length;
//         } else {
//             length++;
//         }
//     }
//     return length;
// }

// int main(void) {
//     char stringg[] = "Hello World  ";
//     int size = lengthOfLastWord(stringg);
//     printf("%d", size);
    
//     return 0;
// }