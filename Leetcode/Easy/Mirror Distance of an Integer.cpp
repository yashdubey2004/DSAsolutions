class Solution {
    int reverse(int n){
        int m = 0;
        while(n > 0){
            int rem = n % 10;
            m = m * 10;
            m += rem;
            n = n / 10;
        }
        return m;
    }

    public int mirrorDistance(int n) {
        int m = reverse(n);
        int result = 0;
        if(m > n) result = m - n;
        else result = n - m;
        return result;
    }
}
