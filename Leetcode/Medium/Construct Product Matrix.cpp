class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int> nums;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                nums.push_back(grid[i][j]);
            }
        }
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] = (prefix[i - 1] % 12345) * (nums[i - 1] % 12345) % 12345;
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            suffix[i] = (suffix[i + 1] % 12345) * (nums[i + 1] % 12345) % 12345;
        }
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            temp.push_back((prefix[i] * suffix[i]) % 12345);
        }
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size(), -1));
        int idx = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                result[i][j] = temp[idx];
                idx++;
            }
        }
        return result;
    }
};
