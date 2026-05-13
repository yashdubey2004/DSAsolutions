class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it : mpp) {
            res.push_back(it.second);
        }
        return res;
    }
};
