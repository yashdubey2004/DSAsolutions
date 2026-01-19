class Solution {
public:
    int vowelConsonantScore(string s) {
        int c = 0, v = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u') v++;
            else if(isalpha(s[i]))c++;
        }
        int res = 0;
        if(c > 0) res = floor(v / c);
        return res;
    }
};
