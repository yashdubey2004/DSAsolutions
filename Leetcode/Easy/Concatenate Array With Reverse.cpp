class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n * 2);
        for(int i = 0; i < nums.size(); i++){
            res[i] = nums[i];
            res[i + n] = nums[n - i - 1];
        }
        return res;
    }
};
