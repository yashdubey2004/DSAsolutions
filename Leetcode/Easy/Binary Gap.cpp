class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int maxGap = 0;
        int pos = 0;

        while(n > 0){
            if(n % 2 == 1){
                if(prev != -1){
                    maxGap = max(maxGap, pos - prev);
                }
                prev = pos;
            }
            n /= 2;
            pos++;
        }

        return maxGap;
    }
};
