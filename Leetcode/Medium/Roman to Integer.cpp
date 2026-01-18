class Solution {
public:
    int romanToInt(string s) {
        int val = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == 'I') {
                val += 1;
            }
            else if(s[i] == 'V') {
                if(i > 0 && s[i - 1] == 'I') {
                    val += 4;
                    i--;
                } else {
                    val += 5;
                }
            }
            else if(s[i] == 'X') {
                if(i > 0 && s[i - 1] == 'I') {
                    val += 9;
                    i--;
                } else {
                    val += 10;
                }
            }
            else if(s[i] == 'L') {
                if(i > 0 && s[i - 1] == 'X') {
                    val += 40;
                    i--;
                } else {
                    val += 50;
                }
            }
            else if(s[i] == 'C') {
                if(i > 0 && s[i - 1] == 'X') {
                    val += 90;
                    i--;
                } else {
                    val += 100;
                }
            }
            else if(s[i] == 'D') {
                if(i > 0 && s[i - 1] == 'C') {
                    val += 400;
                    i--;
                } else {
                    val += 500;
                }
            }
            else if(s[i] == 'M') {
                if(i > 0 && s[i - 1] == 'C') {
                    val += 900;
                    i--;
                } else {
                    val += 1000;
                }
            }
        }
        return val;
    }
};
