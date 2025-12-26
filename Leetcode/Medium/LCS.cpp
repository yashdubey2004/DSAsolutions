class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        // code here
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
