class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int answer = 0;
        unordered_set<int> even,odd;
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> evenSet, oddSet;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % 2 == 0)
                    evenSet.insert(nums[j]);
                else
                    oddSet.insert(nums[j]);
                if (evenSet.size() == oddSet.size()) {
                    answer = max(answer, j - i + 1);
                }
            }
        }
        return answer;
    }
};
