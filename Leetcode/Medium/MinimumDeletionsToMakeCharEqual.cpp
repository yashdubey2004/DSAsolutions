class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char, long long> mpp;
        long long total = 0;

        for(int i = 0; i < s.size(); i++){
            total += cost[i];
            mpp[s[i]] += cost[i];
        }

        long long keep = 0;
        for(auto &it : mpp){
            keep = max(keep, it.second);
        }

        return total - keep;
    }
};
