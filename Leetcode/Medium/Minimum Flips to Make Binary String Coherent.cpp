class Solution {
public:
    int minFlips(string s) {
        int res = INT_MAX;
        int count1 = 0, count0 = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') count0++;
            else count1++;
        }
        if(s[0] == '1' && s[s.length() - 1] == '1' && count1 ==  2) return 0;
        if(s[0] == '1' && s[s.length() - 1] == '1' && count1 > 2){
            res = count1 - 2;
        }
        if(count1 <= 1) return 0;
        if(count0 == 0) return 0;
        res = min(res, count1 - 1);
        res = min(res, count0);
        return res;
    }
};
