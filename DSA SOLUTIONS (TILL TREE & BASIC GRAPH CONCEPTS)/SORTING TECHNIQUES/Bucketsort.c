#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    float buckets[n][n];
    int count[n];
    for (int i = 0; i < n; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        buckets[idx][count[idx]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < count[i]; j++) {
            float temp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > temp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < count[i]; j++)
            arr[index++] = buckets[i][j];
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Bucket Sorted array: ");
    printArray(arr, n);
    return 0;
}
