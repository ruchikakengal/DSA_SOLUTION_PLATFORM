# <div align="Center">Longest Common Subsequence (LCS) Problem</div>

### The Longest Common Subsequence (LCS) problem involves finding the longest sequence that can be derived from two strings while maintaining their respective order. This problem can be solved using Dynamic Programming.
<hr>

### For Example :

## LCS Problem
```
#include <stdio.h>
#include <string.h>

// Function to find the length of the LCS
int lcs(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    return L[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs(X, Y, m, n));

    return 0;
}
```
