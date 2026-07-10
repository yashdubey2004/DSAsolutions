class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {

        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {

                int delrow = r + drow[i];
                int delcol = c + dcol[i];

                if (delrow >= 0 && delrow < n &&
                    delcol >= 0 && delcol < m &&
                    vis[delrow][delcol] == 0 &&
                    grid[delrow][delcol] == '1') {

                    vis[delrow][delcol] = 1;
                    q.push({delrow, delcol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (vis[row][col] == 0 && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return count;
    }
};
