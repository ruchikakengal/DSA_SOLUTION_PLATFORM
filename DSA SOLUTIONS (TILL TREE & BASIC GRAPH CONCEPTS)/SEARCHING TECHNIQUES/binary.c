#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
      int mid=(low+high)/2;
        //int mid = low + (high - low) / 2; // Calculate the middle index

        // If the target is found at mid
        if (arr[mid] == target) {
            return mid; // Return the index of the target
        }

        // If the target is smaller than mid, search the left subarray
        if (arr[mid] > target) {
            high = mid - 1;
        }
        // If the target is larger than mid, search the right subarray
        else {
            low = mid + 1;
        }
    }

    return -1; // Return -1 if the target is not found
}

// Function to print the result
void printResult(int index) {
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
}

int main() {
    int arr[] = {3, 5, 8, 9, 12, 15, 16}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    printf("Searching for element %d...\n", target);

    // Perform binary search
    int index = binarySearch(arr, size, target);

    // Print the result
    printResult(index);

    return 0;
}
