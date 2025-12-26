class Solution {
public:
    int dp[101][101];
    set<string> st;

    void dfs(string &s1, string &s2, int i, int j, string curr){
        if(i == 0 || j == 0){
            reverse(curr.begin(), curr.end());
            st.insert(curr);
            return;
        }

        if(s1[i-1] == s2[j-1]){
            dfs(s1, s2, i-1, j-1, curr + s1[i-1]);
        }
        else{
            if(dp[i-1][j] == dp[i][j])
                dfs(s1, s2, i-1, j, curr);
            if(dp[i][j-1] == dp[i][j])
                dfs(s1, s2, i, j-1, curr);
        }
    }

    vector<string> allLCS(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        dfs(s1, s2, m, n, "");
        return vector<string>(st.begin(), st.end());
    }
};
