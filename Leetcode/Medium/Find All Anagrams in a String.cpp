class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length() > s.length()) return {};
        unordered_map<char, int> pfreq;
        vector<int> res;
        for(int i = 0; i < p.length(); i++){
            pfreq[p[i]]++;
        }
        int left = 0, k = p.length() - 1;
        unordered_map<char, int> sfreq;
        for(int i = 0; i <= k; i++){
            sfreq[s[i]]++;
        }
        int right = k;
        while(right < s.length()){
            if(pfreq == sfreq){
                res.push_back(left);
            }
            sfreq[s[left]]--;
            right++;
            if(right < s.length()) sfreq[s[right]]++;
            if(sfreq[s[left]] == 0) sfreq.erase(s[left]);
            left++;
        }
        return res;
    }
};
