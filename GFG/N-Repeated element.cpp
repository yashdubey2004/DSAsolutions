class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        for(auto& it: freq){
            if(it.second == n){
                return it.first;
            }
        }
        return -1;
    }
};
