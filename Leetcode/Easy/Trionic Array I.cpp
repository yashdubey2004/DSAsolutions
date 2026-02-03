class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool check1 = false, check2 = false, check3 = false;
        int i = 0;
        while (i < nums.size() - 1 && nums[i] < nums[i + 1]) {
            i++;
            check1 = true;
        }
        while (i < nums.size() - 1 && nums[i] > nums[i + 1]) {
            i++;
            check2 = true;
        }
        while (i < nums.size() - 1 && nums[i] < nums[i + 1]) {
            i++;
            check3 = true;
        }
        if (i == nums.size() - 1 && check1 && check2 && check3) {
            return true;
        }
        return false;
    }
};
