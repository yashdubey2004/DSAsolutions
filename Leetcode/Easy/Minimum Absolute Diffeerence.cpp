class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int diff = INT_MAX;
        for(int i = 0; i < arr.size() - 1; i++){
            int d = arr[i + 1] - arr[i];
            diff = min(diff, d);
        }
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] == diff){
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};
