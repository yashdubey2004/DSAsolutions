class Solution {
public:
    bool validDigit(int n, int x) {
        if(n == x) return false;
        int ld = -1;
        bool eq = false;
        while(n > 0){
            int rem = n % 10;
            if(rem == x) eq = true;
            n /= 10;
            if(n < 10){
                ld = n;
                break;
            }
        }
        if(eq == true && ld != x) return true;
        return false;
    }
};
