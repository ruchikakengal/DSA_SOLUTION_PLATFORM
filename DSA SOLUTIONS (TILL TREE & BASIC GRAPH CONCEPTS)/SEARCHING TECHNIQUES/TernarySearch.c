#include <stdio.h>

int ternarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        // Divide the array into three parts
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // If the target is at one of the middle points
        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }

        // Recur in one of the three segments
        if (target < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, target);
        } else if (target > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, target);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
        }
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 12, 15, 17, 19, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = ternarySearch(arr, 0, size - 1, target);
    if (result != -1) {
        printf("Found %d at index %d\n", target, result);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}
