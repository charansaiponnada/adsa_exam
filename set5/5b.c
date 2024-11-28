#include <stdio.h>
#include <stdlib.h>
void print_fib_series(int n) {
    if (n <= 0) return;
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    if (n > 0) dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("Fibonacci series up to %dth term: ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", dp[i]);
    }
    printf("\n");
    free(dp);
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    print_fib_series(n);
    return 0;
}
