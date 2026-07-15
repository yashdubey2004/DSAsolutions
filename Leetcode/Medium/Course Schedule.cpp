class Solution {
public:
    bool detect(int node, vector<vector<int>>& adj,
                vector<int>& vis, vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {

            if (!vis[it]) {
                if (detect(it, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {

            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (detect(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};
