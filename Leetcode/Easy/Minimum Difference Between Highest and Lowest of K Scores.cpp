class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = k - 1;
        int mini = INT_MAX;
        while(right < nums.size()){
            int curr = nums[right] - nums[left];
            left++;
            right++;
            mini = min(mini, curr);
        }
        return mini;
    }
};
