#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n) {
    int dp[W + 1];
    for (int i = 0; i <= W; i++) {
        dp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}
int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: Weight: ", i + 1);
        scanf("%d", &wt[i]);
        printf("Item %d: Value: ", i + 1);
        scanf("%d", &val[i]);
    }
    int result = knapSack(W, wt, val, n);
    printf("Maximum profit: %d\n", result);
    return 0;
}