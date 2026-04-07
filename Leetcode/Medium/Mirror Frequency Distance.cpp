class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        for(char c : s){
            freq[c]++;
        }

        unordered_set<char> visited;
        int sum = 0;

        for(auto it : freq){
            char c = it.first;
            if(visited.count(c)) continue;

            char mirror;
            if(c >= 'a' && c <= 'z'){
                mirror = 'a' + ('z' - c);
            } else if(c >= '0' && c <= '9'){
                mirror = '0' + ('9' - c);
            }

            int f1 = freq[c];
            int f2;
            if(freq.count(mirror)){
                f2 = freq[mirror];
            } else {
                f2 = 0;
            }

            sum += abs(f1 - f2);

            visited.insert(c);
            visited.insert(mirror);
        }

        return sum;
    }
};
