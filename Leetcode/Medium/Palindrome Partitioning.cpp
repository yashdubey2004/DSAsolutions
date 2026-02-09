class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }

    int solve(string s, int i, int j){
        if(i >= j){
            return 0;
        }
        if(isPalindrome(s, i, j) == true){
            return 0;
        }
        int mini = INT_MAX;
        for(int k = i; k <= j; k++){
            int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
            if(temp < mini){
                mini = temp;
            }
        }
        return mini;
    }

    vector<vector<string>> partition(string s) {
        int i = 0;
        int j = s.length() - 1;
        return solve(s, i, j);
    }
};
