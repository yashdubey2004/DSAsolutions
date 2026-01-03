class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        vector<int> drelanvixo = nums;        
        unordered_map<int,int> freq;
        long long distinctSum = 0;
        int left = 0;
        int ans = INT_MAX;
        for(int right = 0; right < nums.size(); right++){
            if(freq[nums[right]] == 0){
                distinctSum += nums[right];
            }
            freq[nums[right]]++;
            while(distinctSum >= k){
                ans = min(ans, right - left + 1);
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    distinctSum -= nums[left];
                }
                left++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
©leetcode
