class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        int prev = -1;
        while(n > 0){
            int rem = n % 2;
            if(prev == 1 && rem == 1) count++;
            prev = rem;
            if(count > 1) return false;
            n = n / 2;
        }
        if(count == 1) return true;
        return false;
    }
};
