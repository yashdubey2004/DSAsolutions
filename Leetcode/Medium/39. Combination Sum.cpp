class Solution {
public:

    void helper(vector<int>& candidates, vector<vector<int>>& result, vector<int>& help, int target, int sum, int idx) {
        if (sum == target) {
            result.push_back(help);
            return;
        }
        if (sum > target) {
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            help.push_back(candidates[i]);
            helper(candidates, result, help, target, sum + candidates[i], i);
            help.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> help;
        helper(candidates, result, help, target, 0, 0);
        return result;
    }
};
