class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int left = 0, currentSum = 0, maxSum = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            int val = nums[right];
            freq[val]++;
            currentSum += val;
            while (freq[val] > 1) {
                freq[nums[left]]--;
                currentSum -= nums[left];
                left++;
            }
            
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
