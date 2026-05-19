class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 0; i < s.length() - 1; i++){
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            int res = abs(a - b);
            if(res > 2) return false;
        }
        return true;
    }
};
