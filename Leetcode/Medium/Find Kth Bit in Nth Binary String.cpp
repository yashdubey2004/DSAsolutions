class Solution {
public:
    void help(string& res, int n){
        if(n == 0) return;
        res += '1';
        int i = res.length() - 2;
        while(i >= 0){
            if(res[i] == '0') res += '1';
            else res += '0';
            i--;
        }
        help(res, n - 1);
    }

    char findKthBit(int n, int k) {
        string res = "0";
        help(res, n);
        return res[k - 1];
    }
};
