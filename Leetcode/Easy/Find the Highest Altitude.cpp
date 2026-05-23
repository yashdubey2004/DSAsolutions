class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> prefixsum(gain.size());
        prefixsum[0] = gain[0];
        int res = prefixsum[0];
        for(int i = 1; i < prefixsum.size(); i++){
            prefixsum[i] = prefixsum[i - 1] + gain[i];
            res = max(res, prefixsum[i]);
        }
        if(res < 0) return 0;
        return res;
    }
};
