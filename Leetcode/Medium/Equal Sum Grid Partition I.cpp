class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long leftsum = 0, rightsum = 0;
        long long topsum = 0, bottomsum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rightsum += grid[i][j];
                bottomsum += grid[i][j];
            }
        }
        for(int j = 0; j < m; j++){
            long long col = 0;
            for(int i = 0; i < n; i++){
                col += grid[i][j];
            }
            rightsum -= col;
            leftsum += col;
            if(j != m - 1 && rightsum == leftsum) return true;
        }
        for(int i = 0; i < n; i++){
            long long row = 0;
            for(int j = 0; j < m; j++){
                row += grid[i][j];
            }
            bottomsum -= row;
            topsum += row;
            if(i != n - 1 && bottomsum == topsum) return true;
        }
        return false;
    }
};
