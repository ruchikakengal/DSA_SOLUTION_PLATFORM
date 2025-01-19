# <div align="Center">Backtracking Approach</div>

### The backtracking approach in programming involves searching for a solution by trying various possibilities and backtracking when a solution cannot be achieved. It is used for problems that require exploring all possible configurations.
<hr>

### For Example :

## Activity Selection Problem
```
#include <stdio.h>
#include <stdbool.h>

// Structure to represent an activity
typedef struct {
    int index;
    int start;
    int end;
} Activity;

void printSelectedActivities(bool selected[], Activity activities[], int n) {
    printf("Selected activities are:\n");
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            printf("Activity %d (Start: %d, End: %d)\n", activities[i].index, activities[i].start, activities[i].end);
        }
    }
}

bool isValidSelection(Activity activities[], bool selected[], int n, int current) {
    for (int i = 0; i < current; i++) {
        if (selected[i] && activities[current].start < activities[i].end) {
            return false;
        }
    }
    return true;
}

bool activitySelection(Activity activities[], bool selected[], int n, int current) {
    if (current == n) {
        printSelectedActivities(selected, activities, n);
        return true;
    }

    selected[current] = true;
    if (isValidSelection(activities, selected, n, current)) {
        if (activitySelection(activities, selected, n, current + 1)) {
            return true;
        }
    }

    selected[current] = false;
    return activitySelection(activities, selected, n, current + 1);
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
    bool selected[n];

    for (int i = 0; i < n; i++) {
        selected[i] = false;
    }

    activitySelection(activities, selected, n, 0);

    return 0;
}
```
