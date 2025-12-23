class Solution {
public:
    void makefreq(vector<int>& nums, unordered_map<int,int>& freq, int idx, int& dupCount) {
        int k = 0;
        for(int i = idx; i < nums.size() && k < 3; i++){
            freq[nums[i]]--;
            if(freq[nums[i]] == 1){
                dupCount--;
            }
            if(freq[nums[i]] == 0){
                freq.erase(nums[i]);
            }
            k++;
        }
    }

    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        int dupCount = 0;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            if(freq[nums[i]] == 2){
                dupCount++;
            }
        }

        if(dupCount == 0) return 0;

        int count = 0;
        int i = 0;

        while(i < nums.size()){
            makefreq(nums, freq, i, dupCount);
            count++;
            i = i + 3;

            if(dupCount == 0){
                return count;
            }
        }

        return count;
    }
};
