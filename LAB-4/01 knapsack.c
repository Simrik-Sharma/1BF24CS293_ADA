#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    // Input weights
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    // Input values
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    // Input capacity
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int dp[n+1][W+1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]],
                               dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    // Backtracking to find selected items
    int w = W;
    printf("Selected items (1-based index): ");

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            printf("%d ", i);
            w -= wt[i-1];
        }
    }

    printf("\n");

    return 0;
}
