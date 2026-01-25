class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i == rows - 1 && j == cols - 1) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int down = INT_MAX;
        int right = INT_MAX;
        if (i + 1 < rows) down = solve(i + 1, j, grid, dp);
        if (j + 1 < cols) right = solve(i, j + 1, grid, dp);
        dp[i][j] = grid[i][j] + min(down, right);
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return solve(0, 0, grid, dp);
    }
};
