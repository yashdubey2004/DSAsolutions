class Solution {
public:
    string largestEven(string s) {
        if(s.length() == 1){
            int n = s[0] - '0';
            if(n % 2 == 0) return s;
            else return "";
        }

        int i = s.length() - 1;
        while(i >= 0){
            int n = s[i] - '0';
            if(n % 2 == 1){
                i--;
            }
            else{
                break;
            }
        }

        if(i < 0) return "";

        string result = "";
        for(int j = 0; j <= i; j++){
            result += s[j];
        }
        return result;
    }
};
