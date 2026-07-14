class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int n, int m,
             int& time, int& freshcount) {

        int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {

            int sz = q.size();
            bool rotten = false;

            while (sz--) {

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {

                    int newr = r + arr[i][0];
                    int newc = c + arr[i][1];

                    if (newr >= 0 && newr < n &&
                        newc >= 0 && newc < m &&
                        grid[newr][newc] == 1) {

                        grid[newr][newc] = 2;
                        freshcount--;
                        q.push({newr, newc});
                        rotten = true;
                    }
                }
            }

            if (rotten)
                time++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;

        int n = grid.size();
        int m = grid[0].size();

        int freshcount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2)
                    q.push({i, j});

                else if (grid[i][j] == 1)
                    freshcount++;
            }
        }

        if (freshcount == 0)
            return 0;

        int time = 0;

        bfs(grid, q, n, m, time, freshcount);

        if (freshcount == 0)
            return time;

        return -1;
    }
};
