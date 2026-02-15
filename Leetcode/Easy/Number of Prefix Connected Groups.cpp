class Solution {
public:
    string change(string s, int k){
        string tara = "";
        for(int i = 0; i < k; i++){
            tara += s[i];
        }
        return tara;
    }

    int prefixConnected(vector<string>& words, int k) {
        vector<string> finwords;
        for(int i = 0; i < words.size(); i++){
            if(words[i].length() >= k){
                finwords.push_back(words[i]);
            }
        }
        for(int i = 0; i < finwords.size(); i++){
            finwords[i] = change(finwords[i], k);
        }
        unordered_map<string, int> freq;
        int count = 0;
        for(int i = 0; i < finwords.size(); i++){
            freq[finwords[i]]++;
        }
        for(auto& it: freq){
            if(it.second > 1){
                count++;
            }
        }
        return count;
    }
};
