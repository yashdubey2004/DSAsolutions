class Solution {
  public:
    int dp[101][101];
    int help(vector<int>& arr, int i, int j){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i; k < j; k++){
            int curr =
                help(arr, i, k) +
                help(arr, k + 1, j) +
                arr[i - 1] * arr[k] * arr[j];
            mini = min(mini, curr);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        memset(dp, -1, sizeof(dp));
        return help(arr, 1, arr.size() - 1);
    }
};
