class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) nums[i]--;
        }
        vector<int> prefixsum(nums.size());
        prefixsum[0] = nums[0];
        for(int i = 1; i < prefixsum.size(); i++){
            prefixsum[i] = prefixsum[i - 1] + nums[i];
        }
        int maxi = 0;
        unordered_map<int, vector<int>> freq;
        for(int i = 0; i < prefixsum.size(); i++){
            if(prefixsum[i] == 0){
                maxi = max(maxi, i + 1);
            }
            if(freq.find(prefixsum[i]) == freq.end()){
                vector<int> nums(2);
                nums[0] = i;
                nums[1] = i;
                freq[prefixsum[i]] = nums;
            }
            else{
                vector<int> nums(2);
                nums[0] = freq[prefixsum[i]][0];
                nums[1] = i;
                freq[prefixsum[i]] = nums;
            }
        }
        for(auto& it: freq){
            vector<int> nums = it.second;
            maxi = max(maxi, nums[1] - nums[0]);
        }
        return maxi;
    }
};
