class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        string ans = "";
        while (n > 0) {
            ans += (n % 2 == 0) ? '1' : '0';
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        int decimal = 0;
        for (int i = 0; i < ans.length(); i++) {
            if (ans[i] == '1') {
                decimal += pow(2, ans.length() - i - 1);
            }
        }
        return decimal;
    }
};
