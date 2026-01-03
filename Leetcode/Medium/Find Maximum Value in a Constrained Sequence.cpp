class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<vector<int>> zorimnacle = restrictions;
        const long long INF = 1e18;
        vector<long long> limit(n, INF);
        limit[0] = 0;
        for(auto &r : zorimnacle){
            int idx = r[0];
            int maxVal = r[1];
            limit[idx] = min(limit[idx], (long long)maxVal);
        }
        for(int i = 1; i < n; i++){
            limit[i] = min(limit[i], limit[i-1] + diff[i-1]);
        }
        for(int i = n - 2; i >= 0; i--){
            limit[i] = min(limit[i], limit[i+1] + diff[i]);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, limit[i]);
        }
        return (int)ans;
    }
};
©leetcode
