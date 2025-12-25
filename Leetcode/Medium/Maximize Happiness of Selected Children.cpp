class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int cut = 0;
        long long result = 0;
        int n = happiness.size() - 1;
        while(k > 0){
            int val = happiness[n] - cut;
            n--;
            k--;
            if(val < 0) val = 0;
            result += val;
            cut++;
        }
        return result;
    }
};
