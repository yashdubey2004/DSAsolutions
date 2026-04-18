class Solution {
public:
    bool check1(string s){
        for(int i = 0; i < s.length(); i++){
            if(s[i] < 'A' || s[i] > 'Z'){
                return false;
            }
        }
        return true;
    }

    bool check2(string s){
        for(int i = 0; i < s.length(); i++){
            if(s[i] < 'a' || s[i] > 'z'){
                return false;
            }
        }
        return true;
    }

    bool check3(string s){
        if(s[0] < 'A' || s[0] > 'Z') return false;
        for(int i = 1; i < s.length(); i++){
            if(s[i] < 'a' || s[i] > 'z'){
                return false;
            }
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        if(check1(word) == true) return true;
        else if(check2(word) == true) return true;
        else if(check3(word) == true) return true;
        return false;
    }
};
