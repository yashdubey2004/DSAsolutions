class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int left = 0, right = 0;

        while(right < nums.size()){
            sum += nums[right];

            while(sum >= target){
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        if(res == INT_MAX) return 0;
        return res;
    }
};
