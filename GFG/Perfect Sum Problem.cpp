class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int zeroCount = 0;
        vector<int> nums;

        for(int x : arr){
            if(x == 0) zeroCount++;
            else nums.push_back(x);
        }

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j){
                    dp[i][j] += dp[i-1][j - nums[i-1]];
                }
            }
        }

        int ans = dp[n][target];

        for(int i = 0; i < zeroCount; i++){
            ans = ans * 2;
        }

        return ans;
    }
};
