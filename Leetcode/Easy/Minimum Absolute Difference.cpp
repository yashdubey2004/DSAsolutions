class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i = 1;
        int mindiff = INT_MAX;
        while(i < arr.size()){
            int diff = arr[i] - arr[i - 1];
            if(diff < mindiff) mindiff = diff;
            i++;
        }
        vector<vector<int>> result;
        for(int i = 1; i < arr.size(); i++){
            int n = arr[i] - arr[i - 1];
            vector<int> temp;
            if(n == mindiff){
                temp.push_back(arr[i - 1]);
                temp.push_back(arr[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
