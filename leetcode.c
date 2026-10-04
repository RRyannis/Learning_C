//Leetcode 198. House Robber
/*You are a professional robber planning to rob houses along a street.
 Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that 
 adjacent houses have security systems connected and it will automatically 
 contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
 return the maximum amount of money you can rob tonight without alerting the police.*/
#include <stdio.h>
int rob(int* nums, int numsSize) {
    int prevMax, currMax, newMax;
    if (numsSize == 1) return nums[numsSize - 1];
    if (numsSize == 2) {
        return (nums[0] > nums[1]) ? nums[0] : nums[1]; 
    }
    prevMax = nums[0];
    currMax = (nums[0] > nums[1]) ? nums[0] : nums[1];
    for (int i = 2; i <= numsSize - 1; i++) {
        newMax = (nums[i] + prevMax > currMax) ? nums[i] + prevMax : currMax;
        prevMax = currMax;
        currMax = newMax;
    }
    return currMax;
}
int main(void) {
    int nums[] = {2,7,9,3,1};
    int res = rob(nums, 5);
    printf("%d \n", res);

    return 0;
}

//LeetCode 70 — Climbing Stairs
/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/
// #include <stdio.h>

// int climbStairs(int n) {
//     if (n <= 2) {
//         return n;
//     }

//     int prev = 1;  
//     int curr = 2;
//     int temp;
//     for (int i = 3; i <= n; i++) {
//         temp = curr;
//         curr = curr + prev;
//         prev = temp;
//     }

//     return curr;
// }

// int main (void) {
//     int n = 9;
//     int result = climbStairs(n);
//     printf("%d", result);
// }

//problem 215 Kth Largest Element in an Array

//option 1 fails 3 cases
// #include <stdio.h>
// int findKthLargest(int* nums, int numsSize, int k) {
//     int low = 0;
//     int high = numsSize - 1;
//     return quickSelect(nums, low, high, k, numsSize);
    
// }

// int swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int partition(int *nums, int low, int high) {

//     int randIndex = low + rand() % (high - low + 1);
//     swap(&nums[randIndex], &nums[high]);

//     int pivot = nums[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         if (nums[j] < pivot) {
//             i++;
//             swap(&nums[i], &nums[j]);
//         }
//     }
//     swap(&nums[i + 1], &nums[high]);
//     return i + 1;
// }
// int quickSelect(int *nums, int low, int high, int k, int numsSize) {
//     int piv = partition(nums, low, high);
//     if (piv == (numsSize - k)) {
//         return nums[piv];
//     } else if (piv > (numsSize-k)) {
//         return quickSelect(nums, low, piv - 1, k, numsSize);
//     } else {
//         return quickSelect(nums, piv + 1, high, k, numsSize);
//     }
// }

// option 2 passes all, with some troubleshooting through glm 5-3
// #include <stdlib.h>   /* rand() */
// #include <stdio.h>
// #include <time.h>

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

/* Hoare partition: on return,
   nums[low..j]   <= pivot
   nums[j+1..high] >= pivot
   Note: j is NOT the final sorted position of any element. */
// int partition(int *nums, int low, int high) {
//     swap(&nums[low], &nums[low + rand() % (high - low + 1)]); /* pivot goes to LOW */
//     int pivot = nums[low];
//     int i = low - 1;
//     int j = high + 1;

//     while (1) {
//         do { i++; } while (nums[i] < pivot);
//         do { j--; } while (nums[j] > pivot);
//         if (i >= j) return j;
//         swap(&nums[i], &nums[j]);
//     }
// }

// int quickSelect(int *nums, int low, int high, int target) {
//     if (low == high) return nums[low];           /* base case changed */
//     int j = partition(nums, low, high);
//     if (target <= j)                             /* '<=', not '=='    */
//         return quickSelect(nums, low, j, target);/* j stays inside    */
//     return quickSelect(nums, j + 1, high, target);
// }

// int findKthLargest(int *nums, int numsSize, int k) {
//     return quickSelect(nums, 0, numsSize - 1, numsSize - k);
// }
// static void fill(int *a, int n) {
//     a[0] = 5; a[1] = 4; a[2] = 3; a[3] = 2; a[4] = 1;
//     for (int i = 5; i < n; i++) a[i] = 1;
// }

// int main(void) {
//     srand((unsigned) time(NULL));

//     int a1[] = {3, 2, 1, 5, 6, 4};
//     printf("test 1: got %d, want 5\n", findKthLargest(a1, 6, 2));

//     int a2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
//     printf("test 2: got %d, want 4\n", findKthLargest(a2, 9, 4));

//     int a3[] = {7, 7, 7, 7, 7};
//     printf("test 3: got %d, want 7\n", findKthLargest(a3, 5, 2));

//     int n = 100000;
//     int *big = malloc(n * sizeof(int));

//     clock_t t0 = clock();
//     fill(big, n);
//     printf("test 4 (k = n-1): got %d, want 1  [%.3fs]\n",
//            findKthLargest(big, n, n - 1),
//            (double)(clock() - t0) / CLOCKS_PER_SEC);

//     t0 = clock();
//     fill(big, n);   /* refill: quickSelect rearranges the array in place */
//     printf("test 5 (k = 1):   got %d, want 5  [%.3fs]\n",
//            findKthLargest(big, n, 1),
//            (double)(clock() - t0) / CLOCKS_PER_SEC);

//     free(big);
//     return 0;
// }
//power of three
// #include <stdio.h>
// #include <stdbool.h>

// bool isPowerOfThree(int n) {
//     if (n <= 0)
//         return false;

//     while (n % 3 == 0) {
//         n /= 3;
//     }
//     return n == 1;
// }

// int main(void) {
//     printf("%d\n", isPowerOfThree(27));
//     printf("%d\n", isPowerOfThree(0));
//     printf("%d\n", isPowerOfThree(9));
//     printf("%d\n", isPowerOfThree(45));
//     printf("%d\n", isPowerOfThree(1));
//     return 0;
// }

// //problem 169 
// #include <stdio.h>

// int majorityElement(int* nums, int numsSize) {
//     int candidate = nums[0];
//     int count = 1;

//     for (int i = 1; i < numsSize; i++) {
//         if (count == 0) {
//             candidate = nums[i];
//             count = 1;
//         } else if (nums[i] == candidate) {
//             count++;
//         } else {
//             count--;
//         }
//     }
//     return candidate;
// }

// int main(void) {
//     int nums1[] = {2, 2, 1, 1, 1, 2, 2};
//     printf("%d\n", majorityElement(nums1, 7));

//     int nums2[] = {3, 2, 3};
//     printf("%d\n", majorityElement(nums2, 3));

//     return 0;
// }



//problem 125 palindrome
// #include <stdio.h>
// #include <stdbool.h>
// #include <ctype.h>
// #include <string.h>

// bool isPalindrome(char* s) {
//     int left = 0;
//     int right = strlen(s) - 1;

//     while (left < right) {
//         while (left < right && !isalnum((unsigned char)s[left]))
//             left++;
//         while (left < right && !isalnum((unsigned char)s[right]))
//             right--;

//         if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right]))
//             return false;

//         left++;
//         right--;
//     }
//     return true;
// }

// int main(void) {
//     printf("%d\n", isPalindrome("A man, a plan, a canal: Panama"));
//     printf("%d\n", isPalindrome("race a car"));
//     printf("%d\n", isPalindrome(" "));
//     printf("%d\n", isPalindrome("0P"));
//     return 0;
// }

// problem 69 sqrt(x)
// #include <stdio.h>
// int mySqrt(int x) {
//     int mid = 0;
//     int low = 0;
//     int high = x;
//     int answer = 0;
//     while(low <= high) {
//         mid = low + (high - low) / 2;

//         if (mid * mid <= x) {
            
//             answer = mid;
//             low = mid + 1;

//         } else {
//             high = mid -1;
//         }
//     }
//     return answer;
// }

// int main(void) {
//     int x = 8;
//     int result = 0;
//     result = mySqrt(x);
//     printf("%d \n", result);

//     return 0;
// }

//problem 704 binary search
// #include <stdio.h>
// int search(int* nums, int numsSize, int target) {
//     int low = 0;
//     int high = numsSize - 1;
//     while(low <= high){
//         int mid = low + (high - low) / 2;

//         if (nums[mid] == target) {
//             return mid;
//         }
//         if ( nums[mid] > target){
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }
//     return -1;
// }
// int main(void) {
//     int arr[] = { 1, 3, 5, 6 };
//     int x = 3;
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int result = search(arr, n, x);
//     printf("%d \n",result);

//     return 0;
// }
//problem 35 search insert position
// #include <stdio.h>
// int searchInsert(int* nums, int numsSize, int target) {
//     int low = 0;
//     int high = numsSize - 1;
//     while (low <= high) {
//         int mid = low + (high - low) / 2;

//         if(nums[mid] == target) {
//             return mid;
//         }
//         if (nums[mid] < target) {
//             low = mid + 1;
//         } else {
//             high = mid-1;
//         }
//     }
//     return low;
// }
// int main(void) {
//     int arr[] = { 1, 3, 5, 6 };
//     int x = 2;
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int result = searchInsert(arr, n, x);
//     printf("%d \n",result);
// }
//problem 20 valid parentheses
// #include <stdio.h>
// #include <string.h>
// bool isValid(char* s)
// {
//     int n = strlen(s);

//     char stack[n];
//     int top = -1;

//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//         {
//             stack[++top] = s[i];
//         }
//         else
//         {
//             if (top == -1)
//                 return false;

//             char opening = stack[top--];

//             if (s[i] == ')' && opening != '(')
//                 return false;

//             if (s[i] == ']' && opening != '[')
//                 return false;

//             if (s[i] == '}' && opening != '{')
//                 return false;
//         }
//     }

//     return top == -1;
// }
// int main(void) {
    
    
//      char* tests[] = {
//         "()",
//         "()[]{}",
//         "(]",
//         "([)]",
//         "{[]}",
//         "(((",
//         ")))",
//         "",
//         "{[()]}"
//     };

//     int numberOfTests = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < numberOfTests; i++) {

//         printf("\"%s\" -> ", tests[i]);

//         if (isValid(tests[i])) {
//             printf("true\n");
//         } else {
//             printf("false\n");
//         }
//     }

//     return 0;
// }
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