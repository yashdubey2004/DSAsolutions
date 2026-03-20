class Solution {
public:
    int makepref(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            int n = makepref(maxi, nums[i]);
            prefixGcd.push_back(n);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int left = 0, right = prefixGcd.size() - 1;
        long long sum = 0;
        while (left < right) {
            int s = makepref(prefixGcd[left], prefixGcd[right]);
            sum += s;
            left++;
            right--;
        }
        return sum;
    }
};
