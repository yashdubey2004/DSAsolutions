class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> newarr;
        for(int i = 0; i < arr.size(); i++){
            newarr.push_back(arr[i]);
        }
        sort(newarr.begin(), newarr.end());
        int cnt = 1;
        unordered_map<int, int> mpp;
        for(int i = 0; i < newarr.size(); i++){
            if(i == 0) mpp[newarr[i]] = cnt;
            else if(newarr[i] != newarr[i - 1]){
                cnt++;
                mpp[newarr[i]] = cnt;
            }
        }
        vector<int> res;
        for(int i = 0; i < arr.size(); i++){
            res.push_back(mpp[arr[i]]);
        }
        return res;
    }
};
