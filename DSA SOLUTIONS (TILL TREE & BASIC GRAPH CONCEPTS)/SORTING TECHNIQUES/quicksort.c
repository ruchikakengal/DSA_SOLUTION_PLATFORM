#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int A[], int l, int h) {
    int pivot = A[l]; 
    int i = l, j = h;
    int temp =0;
    while (i < j) {
        
        do {
            i++;
        } while (A[i] <= pivot);

        
        do {
            j--;
        } while (A[j] > pivot);

        
        if (i < j) {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;

        }
    }

    
    temp=A[l];
    A[l]=A[j];
    A[j]=temp;

    return j;
}


void quickSort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h); 
        quickSort(A, l, j);    
        quickSort(A, j + 1, h);     
    }
}


void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int A[] = {6, 5, 8, 9, 3, 10, 15, 12, 16, 9999}; // 9999 acts as the sentinel/infinity
    int n = sizeof(A) / sizeof(A[0]) - 1;           // Exclude the sentinel value for sorting

    printf("Original array:\n");
    printArray(A, n);

    quickSort(A, 0, n + 1); // Perform Quick Sort

    printf("Sorted array:\n");
    printArray(A, n);

    return 0;
}
