class Solution {
  public:
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        unordered_set<int> st(arr1.begin(), arr1.end());
        unordered_set<int> ft(arr2.begin(), arr2.end());
        unordered_set<int> dt(arr3.begin(), arr3.end());

        vector<int> result;
        for (int num : st) {
            if (ft.count(num) && dt.count(num)) {
                result.push_back(num);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
