class Solution {
public:
    bool hasAlternatingBits(int n) {
        stack<int> st;
        while(n > 0){
            int rem = n % 2;
            if(!st.empty() && st.top() == rem) return false;
            st.push(rem);
            n /= 2;
        }
        return true;
    }
};
