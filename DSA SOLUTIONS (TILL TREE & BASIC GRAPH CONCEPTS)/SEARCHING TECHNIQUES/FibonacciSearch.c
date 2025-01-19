<<<<<<< HEAD
#include <stdio.h>

int fibonacciSearch(int arr[], int size, int target) {
    int fibM_minus_2 = 0;  // (m-2)'th Fibonacci number
    int fibM_minus_1 = 1;  // (m-1)'th Fibonacci number
    int fibM = fibM_minus_2 + fibM_minus_1; // m'th Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to size
    while (fibM < size) {
        fibM_minus_2 = fibM_minus_1;
        fibM_minus_1 = fibM;
        fibM = fibM_minus_2 + fibM_minus_1;
    }

    // Marks the eliminated range from the front
    int offset = -1;

    // Perform the search while fibM is greater than 1
    while (fibM > 1) {
        int i = (offset + fibM_minus_2) < (size - 1) ? (offset + fibM_minus_2) : (size - 1);

        // If target is greater than the value at index fibM_minus_2
        if (arr[i] < target) {
            fibM = fibM_minus_1;
            fibM_minus_1 = fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
            offset = i;
        }
        // If target is smaller, reduce the range
        else if (arr[i] > target) {
            fibM = fibM_minus_2;
            fibM_minus_1 = fibM_minus_1 - fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        }
        // Target found
        else {
            return i;
        }
    }

    // The last comparison
    if (fibM_minus_1 && arr[offset + 1] == target) {
        return offset + 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 60, 70, 80, 85};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 85;

    int result = fibonacciSearch(arr, size, target);
    if (result != -1) {
        printf("Found %d at index %d\n", target, result);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}
=======
#include <stdio.h>

int fibonacciSearch(int arr[], int size, int target) {
    int fibM_minus_2 = 0;  // (m-2)'th Fibonacci number
    int fibM_minus_1 = 1;  // (m-1)'th Fibonacci number
    int fibM = fibM_minus_2 + fibM_minus_1; // m'th Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to size
    while (fibM < size) {
        fibM_minus_2 = fibM_minus_1;
        fibM_minus_1 = fibM;
        fibM = fibM_minus_2 + fibM_minus_1;
    }

    // Marks the eliminated range from the front
    int offset = -1;

    // Perform the search while fibM is greater than 1
    while (fibM > 1) {
        int i = (offset + fibM_minus_2) < (size - 1) ? (offset + fibM_minus_2) : (size - 1);

        // If target is greater than the value at index fibM_minus_2
        if (arr[i] < target) {
            fibM = fibM_minus_1;
            fibM_minus_1 = fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
            offset = i;
        }
        // If target is smaller, reduce the range
        else if (arr[i] > target) {
            fibM = fibM_minus_2;
            fibM_minus_1 = fibM_minus_1 - fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        }
        // Target found
        else {
            return i;
        }
    }

    // The last comparison
    if (fibM_minus_1 && arr[offset + 1] == target) {
        return offset + 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 60, 70, 80, 85};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 85;

    int result = fibonacciSearch(arr, size, target);
    if (result != -1) {
        printf("Found %d at index %d\n", target, result);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}
>>>>>>> 7bad0a68daa2c06c9fca1126fc521408b8718bdd
