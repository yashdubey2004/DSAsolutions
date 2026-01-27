class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixsum(nums.size(), -1), suffixsum(nums.size(), -1);
        prefixsum[0] = 1;
        suffixsum[nums.size() - 1] = 1;
        for(int i = 1; i < nums.size(); i++){
            prefixsum[i] = prefixsum[i - 1] * nums[i - 1]; 
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            suffixsum[i] = suffixsum[i + 1] * nums[i + 1];
        }
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int res = prefixsum[i] * suffixsum[i];
            result.push_back(res);
        }
        return result;
    }
};
