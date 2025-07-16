class Solution {
  public:
    // int solve(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp){
    //     if(W == 0 || n == 0) return 0;
    //     else if(dp[W][n - 1] != -1){
    //         return dp[W][n - 1];
    //     }
    //     else if(wt[n - 1] <= W){
    //         return dp[W][n-1] = max(val[n - 1] + solve(W - wt[n - 1], val, wt, n - 1, dp), solve(W, val, wt, n - 1, dp));
    //     }
    //     else if(wt[n - 1] > W){
    //         return dp[W][n-1] = solve(W, val, wt, n - 1, dp);
    //     }
    // }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w - wt[i - 1]] + val[i - 1],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
};
