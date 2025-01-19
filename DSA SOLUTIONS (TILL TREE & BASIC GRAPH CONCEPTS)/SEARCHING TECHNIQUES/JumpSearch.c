<<<<<<< HEAD
#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;

    // Jump in steps of size `step` and find the block where the target might be
    while (arr[step - 1] < target && step < size) {
        prev = step;
        step += sqrt(size);
        if (step > size) step = size;
    }

    // Perform linear search in the block
    for (int i = prev; i < step; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = jumpSearch(arr, size, target);
    if (result != -1) {
        printf("Found %d at index %d\n", target, result);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}
=======
#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;

    // Jump in steps of size `step` and find the block where the target might be
    while (arr[step - 1] < target && step < size) {
        prev = step;
        step += sqrt(size);
        if (step > size) step = size;
    }

    // Perform linear search in the block
    for (int i = prev; i < step; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = jumpSearch(arr, size, target);
    if (result != -1) {
        printf("Found %d at index %d\n", target, result);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}
>>>>>>> 7bad0a68daa2c06c9fca1126fc521408b8718bdd
