class Solution {
public:
    bool check(int n){
        bool changed = false;
        while(n > 0){
            int rem = n % 10;
            if(rem == 3 || rem == 4 || rem == 7) return false;
            if(rem == 2 || rem == 5 || rem == 6 || rem == 9){
                changed = true;
            }
            n /= 10;
        }
        return changed;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(check(i)) count++;
        }
        return count;
    }
};
