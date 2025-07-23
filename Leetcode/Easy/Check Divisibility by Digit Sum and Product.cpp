class Solution {
public:
    bool checkDivisibility(int n) {
        int digitsum = 0, digitprod = 1;
        int temp = n;
        while(n > 0){
            int rem = n % 10;
            digitsum += rem;
            digitprod *= rem;
            n = n / 10;
        }
        int check = digitsum + digitprod;
        if(temp % check == 0) return true;
        return false;
    }
};
