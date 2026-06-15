class Solution {
public:
    void dfs(vector<int> adjls[], int node, vector<int>& vis){
        vis[node] = 1;
        for(auto& it: adjls[node]){
            if(vis[it] == 0){
                vis[it] = 1;
                dfs(adjls, it, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adjls[n];
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                vis[i] = 1;
                count++;
                dfs(adjls, i, vis);
            }
        }
        return count;
    }
};
