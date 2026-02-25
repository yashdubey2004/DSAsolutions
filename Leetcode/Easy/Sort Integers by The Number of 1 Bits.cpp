class Solution {
public:
    int countBits(int n){
        int count = 0;
        while(n > 0){
            n = n & (n - 1);  // removes one set bit
            count++;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            int countA = countBits(a);
            int countB = countBits(b);

            if(countA == countB)
                return a < b;   
            return countA < countB;
        });

        return arr;
    }
};
