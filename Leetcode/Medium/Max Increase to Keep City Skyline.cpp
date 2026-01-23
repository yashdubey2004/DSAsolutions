class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowMax(grid.size(), 0);
        vector<int> colMax(grid[0].size(), 0);
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int allowed = min(rowMax[i], colMax[j]);
                result += allowed - grid[i][j];
            }
        }
        return result;
    }
};
