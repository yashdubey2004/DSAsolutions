class Solution {
public:
    int help(vector<int>& nums, int left, int right) {
        if(left == right) return nums[left];

        vector<int> dp(right - left + 1, 0);

        dp[0] = nums[left];
        dp[1] = max(nums[left], nums[left + 1]);

        for(int i = 2; i < dp.size(); i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[left + i]);
        }

        return dp[dp.size() - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int a = help(nums, 0, n - 2);
        int b = help(nums, 1, n - 1);

        return max(a, b);
    }
};
