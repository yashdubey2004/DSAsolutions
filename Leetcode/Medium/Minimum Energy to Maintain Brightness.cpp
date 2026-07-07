class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for(auto& it: intervals){
            if(merged.empty() || merged.back()[1] < it[0]){
                merged.push_back(it);
            }
            else{
                merged.back()[1] = max(merged.back()[1], it[1]);
            }
        }

        long long sum = 0;
        for (auto &it : merged) {
            sum += (long long)it[1] - it[0] + 1;
        }

         int mul = ceil(brightness / 3.0);

         return sum * mul;

    }
};
