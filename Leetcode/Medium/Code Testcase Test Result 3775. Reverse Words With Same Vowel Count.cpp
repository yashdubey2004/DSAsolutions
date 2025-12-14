class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int idx = 0;
        int vcount = 0;
        while(idx < s.length() && s[idx] != ' '){
            result += s[idx];
            if(s[idx] == 'a' || s[idx] == 'e' || s[idx] == 'i' || s[idx] == 'o' || s[idx] == 'u'){
                vcount++;
            }
            idx++;
        }
        idx++;
        for(idx; idx < s.length(); idx++){
            string word = "";
            int currcount = 0;
            while(idx < s.length() && s[idx] != ' '){
                word += s[idx];
                if(s[idx] == 'a' || s[idx] == 'e' || s[idx] == 'i' || s[idx] == 'o' || s[idx] == 'u'){
                    currcount++;
                }
                idx++;
            }
            if(currcount == vcount){
                reverse(word.begin(), word.end());
            }
            result += ' ' + word;
        }
        return result;
    }
};
