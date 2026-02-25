class Solution {
public:
    bool isDigitorialPermutation(int n) {
        string a = to_string(n);
        sort(a.begin(), a.end());
        int f0 = 1, f1 = 1, f2 = 2, f3 = 6, f4 = 24, f5 = 120, f6 = 720, f7 = 5040, f8 = 40320, f9 = 362880;
        int sum = 0;
        int tempn = n;
        while(n > 0){
            int rem = n % 10;
            if(rem == 0) sum += f0;
            if(rem == 1) sum += f1;
            if(rem == 2) sum += f2;
            if(rem == 3) sum += f3;
            if(rem == 4) sum += f4;
            if(rem == 5) sum += f5;
            if(rem == 6) sum += f6;
            if(rem == 7) sum += f7;
            if(rem == 8) sum += f8;
            if(rem == 9) sum += f9;
            n /= 10;           
        }
        string b = to_string(sum);
        sort(b.begin(), b.end());
        if(a == b) return true;
        return false;
    }
};
