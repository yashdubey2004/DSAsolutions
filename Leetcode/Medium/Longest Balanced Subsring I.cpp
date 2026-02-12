class Solution {
public:
    int longestBalanced(string s) {
        if(s.length() == 1) return 1;
        int maxi = 0;

        for(int i = 0; i < s.length(); i++){
            unordered_map<char, int> freq;
            for(int j = i; j < s.length(); j++){
                freq[s[j]]++;
                int count = -1;
                bool balanced = true;
                for(auto &it : freq){
                    if(count == -1) count = it.second;
                    else if(count != it.second){
                        balanced = false;
                        break;
                    }
                }

                if(balanced){
                    int len = count * freq.size();
                    maxi = max(maxi, len);
                }
            }
        }

        return maxi;
    }
};
