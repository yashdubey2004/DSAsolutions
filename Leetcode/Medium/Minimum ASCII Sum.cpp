class Solution {
public:
    string makeLCS(vector<vector<int>>& dp, int m, int n, string s1, string s2) {
        string res = "";
        while (m > 0 && n > 0) {
            if (s1[m - 1] == s2[n - 1]) {
                res += s1[m - 1];
                m--;
                n--;
            } else if (dp[m - 1][n] > dp[m][n - 1]) {
                m--;
            } else {
                n--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        int sum = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = s1[i-1] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string lcs = makeLCS(dp, m, n, s1, s2);
        for(int i = 0; i < s1.length(); i++) sum += s1[i];
        for(int i = 0; i < s2.length(); i++) sum += s2[i];
        for(int i = 0; i < lcs.length(); i++) sum -= (2 * lcs[i]);
        return sum;
    }
};
