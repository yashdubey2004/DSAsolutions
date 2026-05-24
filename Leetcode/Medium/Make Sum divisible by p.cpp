class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for(int x : nums) {
            total += x;
        }
        int total_rem = total % p;
        if(total_rem == 0) return 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long prefix = 0;
        int res = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int curr_rem = prefix % p;
            int target = (curr_rem - total_rem + p) % p;
            if(mp.find(target) != mp.end()) {
                res = min(res, i - mp[target]);
            }
            mp[curr_rem] = i;
        }
        if(res == nums.size()) return -1;
        return res;
    }
};
