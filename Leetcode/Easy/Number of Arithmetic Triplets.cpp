class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            if(st.count(nums[i] + diff) && st.count(nums[i] + diff + diff)){
                result++;
            }
        }
        return result;
    }
};
