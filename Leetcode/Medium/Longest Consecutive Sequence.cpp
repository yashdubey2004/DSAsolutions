class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        int res = 0;
        int cnt = 0;
        for(int num : st){
            if(!st.count(num - 1)){
                cnt = 1;
                int curr = num;
                while(st.count(curr + 1)){
                    cnt++;
                    curr++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
