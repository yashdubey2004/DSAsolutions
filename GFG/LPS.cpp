class Solution {
  public:
    int longestPalinSubseq(string &s) {
        string t = "";
        for(int i = s.length() - 1; i >= 0; i--){
            t += s[i];
        }
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
