class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                if(obstacleGrid[i][j] == 1) continue;
                int left = 0, up = 0;
                if(i > 0) left = dp[i - 1][j];
                if(j > 0) up = dp[i][j - 1];
                dp[i][j] = left + up;
            }
        }
        return dp[n - 1][m - 1];
    }
};
