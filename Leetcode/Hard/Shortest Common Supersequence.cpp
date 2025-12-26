class Solution {
public:
    string build(string s1, string s2, string common) {
    int i = 0, j = 0, k = 0;
    string result = "";

    while (k < common.length()) {
        while (i < s1.length() && s1[i] != common[k]) {
            result += s1[i];
            i++;
        }
        while (j < s2.length() && s2[j] != common[k]) {
            result += s2[j];
            j++;
        }
        result += common[k];
        i++;
        j++;
        k++;
    }
    while (i < s1.length()) {
        result += s1[i++];
    }
    while (j < s2.length()) {
        result += s2[j++];
    }

    return result;
}


    string trace(string &s1, string &s2, vector<vector<int>>& dp, int i, int j){
    string lcs = "";

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            lcs += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j -1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j -1]);
                }
            }
        }
        string common = trace(str1, str2, dp, m, n);
        string result = build(str1, str2, common);
        return result;
    }
};
