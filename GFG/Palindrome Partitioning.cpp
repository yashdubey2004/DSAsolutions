class Solution {
  public:
    bool isPalindrome(string &s, int i, int j){
        while(i <= j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    int solve(string &s, int i, int j, vector<vector<int>> &dp){
        if(i >= j) return 0;

        if(isPalindrome(s, i, j)) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k = i; k < j; k++){   // IMPORTANT FIX
            int temp = solve(s, i, k, dp) 
                     + solve(s, k + 1, j, dp) 
                     + 1;
            mini = min(mini, temp);
        }

        return dp[i][j] = mini;
    }

    int palPartition(string &s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};
