class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];
        }

        int target = sum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                if(arr[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int result = INT_MAX;

        for(int j = 0; j <= target; j++){
            if(dp[n][j]){
                int diff = abs(sum - 2*j);
                result = min(result, diff);
            }
        }

        return result;
    }
};
