#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
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
    int arr[] = {3, 5, 8, 9, 12, 15, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    printf("Searching for element %d...\n", target);

    // Perform linear search
    int index = linearSearch(arr, size, target);

    // Print the result
    printResult(index);

    return 0;
}
