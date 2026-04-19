#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maskPII(string s) {
        if(s.find('@') != string::npos)
            return maskEmail(s);
        else
            return maskPhone(s);
    }

    string maskPhone(string s){
        string digits = "";
        for(char c : s){
            if(isdigit(c)) digits += c;
        }

        int n = digits.size();
        string res = "";

        if(n > 10){
            res += '+';
            for(int i = 0; i < n - 10; i++) res += '*';
            res += '-';
        }

        res += "***-***-";
        res += digits.substr(n - 4);

        return res;
    }

    string maskEmail(string s){
        string res = "";
        int at = s.find('@');

        res += tolower((unsigned char)s[0]);
        res += "*****";
        res += tolower((unsigned char)s[at - 1]);

        for(int i = at; i < s.size(); i++){
            res += tolower((unsigned char)s[i]);
        }

        return res;
    }
};
