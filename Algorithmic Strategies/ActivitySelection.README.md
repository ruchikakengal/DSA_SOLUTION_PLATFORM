# <div align="Center">Brute Force Approach</div>

### The brute force approach in programming refers to a straightforward method to solve a problem by trying all possible solutions and selecting the best one. While it is simple to implement, it is often inefficient for large inputs.
<hr>

### For Example :

## Activity Selection Problem
```
#include <stdio.h>

void activitySelection(int start[], int end[], int n) {
    printf("Selected activities are:\n");

    for (int i = 0; i < n; i++) {
        int selected = 1; // Assume activity i can be selected
        for (int j = 0; j < n; j++) {
            if (i != j && start[i] < end[j] && start[j] < end[i]) {
                selected = 0; // Overlap found, cannot select
                break;
            }
        }
        if (selected) {
            printf("Activity %d (Start: %d, End: %d)\n", i + 1, start[i], end[i]);
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    activitySelection(start, end, n);

    return 0;
}
