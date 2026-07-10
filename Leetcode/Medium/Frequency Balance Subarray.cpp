class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            unordered_map<int, int> freq;
            unordered_map<int, int> cntFreq;

            for (int j = i; j < n; j++) {

                int x = nums[j];

                if (freq.count(x)) {
                    cntFreq[freq[x]]--;
                    if (cntFreq[freq[x]] == 0)
                        cntFreq.erase(freq[x]);
                }

                freq[x]++;
                cntFreq[freq[x]]++;

                if (freq.size() == 1) {
                    ans = max(ans, j - i + 1);
                    continue;
                }

                if (cntFreq.size() != 2)
                    continue;

                auto it = cntFreq.begin();
                int f1 = it->first;
                int c1 = it->second;
                ++it;
                int f2 = it->first;
                int c2 = it->second;

                int mini = min(f1, f2);
                int maxi = max(f1, f2);

                if (maxi == 2 * mini) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
