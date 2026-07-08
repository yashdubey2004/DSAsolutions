class Solution {
public:
    long long sumOfGoodIntegers(int n, int k) {
        long long sum = 0;
        for(int i = max(1, n - k); i <= n + k; i++){
            if(abs(n - i) <= k && (n & i) == 0){
                sum += i;
            }
        }
        return sum;
    }
};
