class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        for(int i = 0; i < dp.size(); i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < sum + 1; j++){
                if(coins[i-1] <= j) dp[i][j] = dp[i -1][j] + dp[i][j - coins[i - 1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};
