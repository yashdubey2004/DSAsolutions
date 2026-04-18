#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean = "";
        
        for(char c : s){
            if(c != '-')
                clean += toupper(c);
        }

        string res = "";
        int cnt = 0;

        for(int i = clean.size() - 1; i >= 0; i--){
            if(cnt == k){
                res += '-';
                cnt = 0;
            }
            res += clean[i];
            cnt++;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
