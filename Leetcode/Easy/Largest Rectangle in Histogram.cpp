class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevsmall(heights.size());
        vector<int> nextsmall(heights.size());
        stack<int> st;

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                nextsmall[i] = -1;
            }
            else{
                nextsmall[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = heights.size() - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                prevsmall[i] = heights.size();
            }
            else{
                prevsmall[i] = st.top();
            }
            st.push(i);
            
        }

        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            int area = heights[i] * (prevsmall[i] - nextsmall[i] - 1);
            res = max(res, area);
        }
        return res;
    }
};
