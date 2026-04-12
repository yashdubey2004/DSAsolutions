class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> res(matrix.size(), 0);
        int count = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 1){
                    count++;
                }
            }
            res[i] = count;
            count = 0;
        }
        return res;
    }
};
