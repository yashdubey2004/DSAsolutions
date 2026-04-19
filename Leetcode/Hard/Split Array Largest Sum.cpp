class Solution {
public:
    int check(vector<int>& nums, int val) {
        int count = 0;
        int returncount = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (count + nums[i] > val) {
                returncount++;
                count = nums[i];
            } else {
                count += nums[i];
            }
        }
        return returncount;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int ans = check(nums, mid);
            if (ans > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
