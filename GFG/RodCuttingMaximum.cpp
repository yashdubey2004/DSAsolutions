// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        vector<int> rod;
        for(int i = 1; i <= price.size(); i++){
            rod.push_back(i);
        }
        int n = price.size();
        vector<vector<int>>dp(n + 1, vector<int> (n + 1, 0));
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(rod[i - 1] <= j){
                    dp[i][j] = max(dp[i - 1][j], price[i-1] + dp[i][j - rod[i - 1]]);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][n];
    }
};
