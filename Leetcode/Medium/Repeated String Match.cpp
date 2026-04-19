class Solution {
public:
    int help(string a, string b, string temp, int cnt){
        if(a.find(b) != string::npos){
            return cnt;
        }
        if(a.length() > b.length() + temp.length()){
            return -1;
        }
        a += temp;
        return help(a, b, temp, cnt + 1);
    }
    int repeatedStringMatch(string a, string b) {
        return help(a, b, a, 1);
    }
};
