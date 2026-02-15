class Solution {
public:
    int makesum(string s, unordered_map<char, int>& alphabets){
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            sum += alphabets[s[i]];
        }
        return sum % 26;
    }

    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char, int> alphabets;

        for(int i = 0; i < 26; i++){
            alphabets['a' + i] = weights[i];
        }

        string res = "";

        for(int i = 0; i < words.size(); i++){
            int sum = makesum(words[i], alphabets);
            res += char('z' - sum);
        }

        return res;
    }
};
