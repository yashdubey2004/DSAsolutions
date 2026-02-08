class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum -= nums[i];
            n--;
            int avg = 0;
            if(n > 0) avg = sum / n;
            if(nums[i] > avg){
                count++;
            }
        }
        return count - 1;
    }
};
