class Solution {
public:
    string help(string s, int len, unordered_set<string>& st){
        if(s.length() == len){
            if(!st.count(s)) return s;
            return "";
        }

        string left = help(s + '0', len, st);
        if(left != "") return left;

        return help(s + '1', len, st);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        return help("", nums[0].length(), st);
    }
};
