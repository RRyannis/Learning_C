#include <stdio.h>

int binary_search(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;   /* not found */
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6;

    printf("index: %d\n", binary_search(arr, n, 7));   /* 3 */
    printf("index: %d\n", binary_search(arr, n, 4));   /* -1 */

    return 0;
}