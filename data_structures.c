#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // return the index
        }
    }

    return -1; // not found
}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    // DATA STRUCTURE: Array
    int numbers[] = {5, 2, 8, 1, 9};
    int size = 5;

    // ALGORITHM: Searching
    int target = 8;
    int position = linearSearch(numbers, size, target);

    if (position != -1)
        printf("Found %d at index %d\n", target, position);
    else
        printf("Not found\n");

    // ALGORITHM: Sorting
    bubbleSort(numbers, size);

    printf("Sorted array: ");

    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}