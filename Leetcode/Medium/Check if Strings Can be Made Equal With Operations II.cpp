class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> evens1, evens2, odds1, odds2;
        for(int i = 0; i < s1.length(); i++){
            if(i % 2 == 0){
                evens1[s1[i]]++;
            }
            else odds1[s1[i]]++;
        }
        for(int i = 0; i < s2.length(); i++){
            if(i % 2 == 0){
                evens2[s2[i]]++;
            }
            else odds2[s2[i]]++;
        }
        if(evens1 == evens2 && odds1 == odds2) return true;
        return false;
    }
};
