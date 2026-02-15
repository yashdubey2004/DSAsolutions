class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        unordered_map<int, int> finalfreq;
        for(auto& it: freq){
            finalfreq[it.second]++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(finalfreq[freq[nums[i]]] == 1) return nums[i];
        }
        return -1;
    }
};
