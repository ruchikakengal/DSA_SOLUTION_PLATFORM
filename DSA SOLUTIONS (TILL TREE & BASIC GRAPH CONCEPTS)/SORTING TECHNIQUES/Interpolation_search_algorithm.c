#include <stdio.h>

// Function to perform Interpolation Search
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        // Estimate the position of the target using the interpolation formula
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));

        // Check if the position index is the target
        if (arr[pos] == key)
            return pos;

        // If the key is larger, ignore the lower part
        if (arr[pos] < key)
            low = pos + 1;

        // If the key is smaller, ignore the upper part
        else
            high = pos - 1;
    }

    // Key not found in the array
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = interpolationSearch(arr, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
