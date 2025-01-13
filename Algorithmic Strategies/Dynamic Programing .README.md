# <div align="Center">Dynamic Programming Approach</div>

### The dynamic programming approach in programming involves solving problems by breaking them down into overlapping subproblems and storing the solutions to subproblems to avoid redundant computations. This approach is efficient for problems with optimal substructure and overlapping subproblems.
<hr>

### For Example :

## Activity Selection Problem
```
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void activitySelection(int start[], int end[], int n) {
    int dp[n][n]; // dp[i][j] represents the maximum number of activities in the range [i, j]

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int length = 1; length < n; length++) {
        for (int i = 0; i < n - length; i++) {
            int j = i + length;
            for (int k = i + 1; k < j; k++) {
                if (end[i] <= start[k] && end[k] <= start[j]) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + 1);
                }
            }
        }
    }

    printf("Maximum number of non-overlapping activities: %d\n", dp[0][n - 1]);
}

int main() {
    int start[] = {0, 1, 3, 5, 5, 8};
    int end[] = {6, 2, 4, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    activitySelection(start, end, n);

    return 0;
}
```
