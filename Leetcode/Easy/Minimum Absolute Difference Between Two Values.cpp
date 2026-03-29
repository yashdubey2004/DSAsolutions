class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if((nums[i] == 1 && nums[j] == 2) || (nums[i] == 2 && nums[j] == 1)) res = min(res, abs(j - i));
            }
        }
        if(res == INT_MAX) res = -1;
        return res;
    }
};
