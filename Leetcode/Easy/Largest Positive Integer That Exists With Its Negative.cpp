class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        int maxi = -1;
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            if(val > 0){
                if(freq.find(-val) != freq.end()){
                    if(val > maxi){
                        maxi = val;
                    }
                }
            }
        }
        return maxi;
    }
};
