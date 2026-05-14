class Solution {
public:

    bool allContains(unordered_map<char, int>& tpp,
                     unordered_map<char, int>& toc) {

        for(auto& it : tpp) {

            if(toc[it.first] < it.second) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {

        unordered_map<char, int> t_freq;

        for(char c : t) {
            t_freq[c]++;
        }

        unordered_map<char, int> toc;

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.length(); right++) {

            toc[s[right]]++;

            while(allContains(t_freq, toc)) {

                int windowLen = right - left + 1;

                if(windowLen < minLen) {
                    minLen = windowLen;
                    start = left;
                }

                toc[s[left]]--;
                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
