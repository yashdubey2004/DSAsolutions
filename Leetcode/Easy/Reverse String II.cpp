class Solution {
public:
    void make(string& s, int i, int k){
        int left = i;
        int right = min(i + k - 1, (int)s.length() - 1);
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i += 2 * k){
            make(s, i, k);
        }
        return s;
    }
};
