class Solution {
public:
    int minRemoval(vector<int>& a, int b) {
        sort(a.begin(), a.end());
        int n = a.size();
        int c = n;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && a[j] <= a[i] * (long long)b) ++j;
            c = min(c, i + n - j);
        }
        return c;
    }
};
