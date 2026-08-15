//two sum

// #include <stdio.h>

// int *twoSum(int nums[], int numsSize, int target, int *returnSize);

// int main(void)
// {
//     int nums[] = {2, 7, 11, 15};
//     int target = 9;
//     int returnSize;

//     int *result = twoSum(nums, 4, target, &returnSize);
//     printf("[%d, %d]\n", result[0], result[1]);

//     return 0;
// }

// int *twoSum(int nums[], int numsSize, int target, int *returnSize)
// {
//     static int result[2];   
//     int i, j;

//     for (i = 0; i < numsSize; i++) {
//         for (j = i + 1; j < numsSize; j++) {
//             if (nums[i] + nums[j] == target) {
//                 result[0] = i;
//                 result[1] = j;
//                 *returnSize = 2;
//                 return result;
//             }
//         }
//     }

//     *returnSize = 0;
//     return NULL; 
// }

//profit
#include <stdio.h>

int maxProfit(int prices[], int pricesSize);

int main(void)
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = 6;

    printf("max profit: %d\n", maxProfit(prices, size));

    return 0;
}

int maxProfit(int prices[], int pricesSize)
{
    int min_price = prices[0];
    int max_profit = 0;
    int i;

    for (i = 1; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];          /* found a new lower buy price */
        } else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;  /* found a better profit */
        }
    }

    return max_profit;
}