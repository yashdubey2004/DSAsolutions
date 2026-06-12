class Solution {
  public:
    void help(vector<vector<int>>& adj, int node, int n, vector<int>& vis, vector<int>& res){
        res.push_back(node);
        for(auto& it: adj[node]){
            if(vis[it] == 0){
                vis[it] = 1;
                help(adj, it, n, vis, res);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        // Code here
        vector<int> res;
        int node = 0;
        vector<int> vis(n, 0);
        vis[0] = 1;
        help(adj, node, n, vis, res);
        return res;
    }
};
