class Solution {
public:
    const int MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> yCount;
        for (auto& pt : points)
            yCount[pt[1]]++;

        vector<long long> pairs;
        for (auto& kv : yCount)
            if (kv.second >= 2)
                pairs.push_back(1LL * kv.second * (kv.second - 1) / 2);
        if (pairs.empty())
            return 0;

        long long total = 0, sqrSum = 0;
        for (auto x : pairs) {
            total = (total + x) % MOD;
            sqrSum = (sqrSum + x * x % MOD) % MOD;
        }

        long long ans = (total * total % MOD - sqrSum + MOD) % MOD;
        ans = ans * ((MOD + 1) / 2) % MOD;

        return ans;
    }
};
