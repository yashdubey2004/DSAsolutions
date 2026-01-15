class Solution {
public:
    string reverseOnlyLetters(string s) {
        string letters = "";
        
        for(int i = s.length() - 1; i >= 0; i--){
            if(isalpha(s[i])){
                letters += s[i];
            }
        }

        int idx = 0;
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                s[i] = letters[idx++];
            }
        }
        return s;
    }
};
