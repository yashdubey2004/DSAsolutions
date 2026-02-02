class Solution {
public:
    int countMonobit(int n) {
        if (n < 0) return 0;
        return 1 + floor(log2(n + 1));
    }
};
