class Solution {
public:
    int help(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (i >= m || j >= n || grid[i][j] == 1) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] =
            help(grid, i + 1, j, dp) + help(grid, i, j + 1, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return help(obstacleGrid, 0, 0, dp);
    }
};
