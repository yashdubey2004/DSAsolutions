class Solution {
public:
    string trimTrailingVowels(string s) {
        int i = s.length() - 1;
        while(i >= 0){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                s.erase(i, 1);
                i--;
            }
            else break;
        }
        return s;
    }
};
