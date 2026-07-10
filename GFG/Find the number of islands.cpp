class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {

                    if (i == 0 && j == 0) continue;

                    int nrow = r + i;
                    int ncol = c + j;

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        vis[nrow][ncol] == 0 &&
                        grid[nrow][ncol] == 'L') {

                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {

        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (!vis[row][col] && grid[row][col] == 'L') {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return count;
    }
};
