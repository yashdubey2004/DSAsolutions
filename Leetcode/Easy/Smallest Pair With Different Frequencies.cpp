class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        vector<pair<int, int>> v;
        for (auto &it : freq) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first != v[0].first) {
                return {v[0].second, v[i].second};
            }
        }

        return {-1, -1};
    }
};
