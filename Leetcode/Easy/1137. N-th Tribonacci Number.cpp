class Solution {
public:
    void calc(int n, int &sum, int &a, int &b, int &c){
        if(n == 0){
            sum = c;
            return;
        }
        sum = a + b + c;
        a = b;
        b = c;
        c = sum;
        calc(n - 1, sum, a, b, c);
    }

    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        int a = 0, b = 1, c = 1;
        int sum = 0;

        calc(n - 2, sum, a, b, c);
        return sum;
    }
};
