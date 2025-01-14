# <div align="Center">Greedy Approach</div>

### The greedy approach in programming involves making the locally optimal choice at each stage with the hope of finding the global optimum. It is efficient for problems where this strategy leads to the best solution.
<hr>

### For Example :

## Activity Selection Problem
```
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
typedef struct {
    int index;
    int start;
    int end;
} Activity;

// Comparison function to sort activities by their finishing times
int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->end - activityB->end;
}

void activitySelection(Activity activities[], int n) {
    // Sort activities by their end time
    qsort(activities, n, sizeof(Activity), compare);

    printf("Selected activities are:\n");

    // The first activity is always selected
    int lastSelectedEnd = activities[0].end;
    printf("Activity %d (Start: %d, End: %d)\n", activities[0].index, activities[0].start, activities[0].end);

    // Consider the remaining activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastSelectedEnd) {
            printf("Activity %d (Start: %d, End: %d)\n", activities[i].index, activities[i].start, activities[i].end);
            lastSelectedEnd = activities[i].end;
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
