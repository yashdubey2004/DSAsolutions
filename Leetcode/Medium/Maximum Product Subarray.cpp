class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cmax = nums[0], cmin = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0) swap(cmax, cmin);
            cmax = max(nums[i], cmax * nums[i]);
            cmin = min(nums[i], cmin * nums[i]);
            ans = max(ans, cmax);
        }
        return ans;
    }
};
