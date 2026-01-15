class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int left = 0, right = 0;
        string result = "";
        while(left < word1.length() && right < word2.length()){
            result += word1[left];
            result += word2[right];
            left++;
            right++;
        }
        while(left < word1.length()){
            result += word1[left];
            left++;
        }
        while(right < word2.length()){
            result += word2[right];
            right++;
        }
        return result;
    }
};
