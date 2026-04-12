class Solution {
public:
    int cnt(int n, int k){
        int count = 0;
        while(n > 0){
            int rem = n % 10;
            n = n / 10;
            if(rem == k){
                count++;
            } 
        }
        return count;
    }

    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += cnt(nums[i], digit);
        }
        return count;
    }
};
