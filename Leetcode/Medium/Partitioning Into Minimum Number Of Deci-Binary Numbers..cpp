class Solution {
public:
    int minPartitions(string n) {
        int res = -1;
        for(int i = 0; i < n.length(); i++){
            int num = n[i] - '0';
            if(num > res) res = num;
        }
        return res;
    }
};
