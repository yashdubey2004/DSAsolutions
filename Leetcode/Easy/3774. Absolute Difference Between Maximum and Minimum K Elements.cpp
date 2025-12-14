class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int maxi = 0, mini = 0;
        while(k > 0){
            maxi += nums[j];
            mini += nums[i];
            i++;
            j--;
            k--;
        }
        return maxi - mini;
    }
};
