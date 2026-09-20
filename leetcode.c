//problem 136 single number
#include <stdio.h>
int singleNumber(int* nums, int numsSize){
    int result = 0;
    for (int i = 0; i <= numsSize-1; i++) {
        result ^= nums[i];
        printf("%d \n", result);
    }
    return result;
}

int main(void) {
    int nums[] = {4, 1, 2, 1, 2};
    int lengthOfNums = sizeof(nums)/sizeof(nums[0]);
    printf("%d \n", singleNumber(nums, lengthOfNums));
    
    
    return 0;
}

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