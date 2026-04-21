class Solution {
public:
    int stable(vector<int>& nums, int idx){
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i <= idx; i++){
            maxi = max(maxi, nums[i]);
        }
        for(int i = idx; i < nums.size(); i++){
            mini = min(mini, nums[i]);
        }
        return maxi - mini;
    }

    int firstStableIndex(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            int n = stable(nums, i);
            if(n <= k){
                return i;
            }
        }
        return -1;
    }
};
