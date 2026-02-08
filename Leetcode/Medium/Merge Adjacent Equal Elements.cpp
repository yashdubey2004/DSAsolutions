class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        for(int i = 0; i < nums.size(); i++){
            if(st.empty()){
                st.push(nums[i]);
            }
            else if(nums[i] == st.top()){
                long long newnum = nums[i] * 2;
                st.pop();
                while(!st.empty()&& newnum == st.top()){
                    newnum *= 2;
                    if(!st.empty()) st.pop();
                }
                st.push(newnum);
            }
            else{
                st.push(nums[i]);
            }
        }
        vector<long long> res(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
