class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>>dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        int lcs = dp[m][n];
        int l1 = m - lcs;
        int l2 = n - lcs;
        int result = l1 + l2;
        return result;
    }
};
