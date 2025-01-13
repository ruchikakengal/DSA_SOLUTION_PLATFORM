# <div align="Center">Branch-and-Bound Approach</div>

### The branch-and-bound approach in programming is a systematic method for solving optimization problems. It involves breaking the problem into smaller subproblems (branching) and using bounds to eliminate suboptimal solutions efficiently.
<hr>

### For Example :

## Activity Selection Problem
```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent an activity
typedef struct {
    int index;
    int start;
    int end;
} Activity;

// Comparison function to sort activities by finishing times
int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->end - activityB->end;
}

// Function to solve activity selection problem using branch-and-bound
void activitySelection(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), compare);

    bool selected[n];
    for (int i = 0; i < n; i++) {
        selected[i] = false;
    }

    selected[0] = true; // Always select the first activity
    int lastSelectedEnd = activities[0].end;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastSelectedEnd) {
            selected[i] = true;
            lastSelectedEnd = activities[i].end;
        }
    }

    printf("Selected activities are:\n");
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            printf("Activity %d (Start: %d, End: %d)\n", activities[i].index, activities[i].start, activities[i].end);
        }
    }
}

int main() {
    Activity activities[] = {
        {1, 1, 2},
        {2, 3, 4},
        {3, 0, 6},
        {4, 5, 7},
        {5, 8, 9},
        {6, 5, 9}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}
```
