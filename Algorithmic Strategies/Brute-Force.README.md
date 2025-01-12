# <div align="Center">Brute Force Approach</div>

### The brute force approach in programming refers to a straightforward method to solve a problem by trying all possible solutions and selecting the best one. While it is simple to implement, it is often inefficient for large inputs.
<hr>

### For Example :

## Finding the Largest Element in an Array
```
#include <stdio.h>

int findLargest(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {1, 5, 8, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int largest = findLargest(arr, n);
    printf("The largest element is: %d\n", largest);
    
    return 0;
}

```
