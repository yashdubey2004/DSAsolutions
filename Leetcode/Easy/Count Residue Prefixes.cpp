class Solution {
public:
    int residuePrefixes(string s) {
        int count = 0;
        unordered_set<char> st;
        int result = 0;
        for(int i = 0; i < s.length(); i++){
            if(!st.count(s[i])){
                st.insert(s[i]);
                count++;
            }
            int curr = (i + 1) % 3;
            if(curr == count) result++;
        }
        return result;
    }
};
