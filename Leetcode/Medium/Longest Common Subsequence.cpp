class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};


// class Solution {
// public:
//     static int dp[1001][1001];

//     int help(string& s1, string& s2, int i, int j){
//         if(i < 0 || j < 0){
//             return 0;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         if(s1[i] == s2[j]){
//             return dp[i][j] = 1 + help(s1, s2, i - 1, j - 1);
//         }

//         return dp[i][j] = max(
//             help(s1, s2, i - 1, j),
//             help(s1, s2, i, j - 1)
//         );
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         memset(dp, -1, sizeof(dp));
//         return help(text1, text2, text1.length() - 1, text2.length() - 1);
//     }
// };

// int Solution::dp[1001][1001];

