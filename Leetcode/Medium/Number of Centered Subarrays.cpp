class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            unordered_map<int, int> freq;
            for(int j = i; j < nums.size(); j++){
                freq[nums[j]]++;
                sum += nums[j];
                if(freq[sum] > 0){
                    count++;
                }
            }
        }
        return count;
    }
};
