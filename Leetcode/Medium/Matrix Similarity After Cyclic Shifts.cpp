class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> original = mat;
        
        while(k--){
            for(int i = 0; i < m; i++){
                if(i % 2 == 0){
                    int first = mat[i][0];
                    for(int j = 0; j < n - 1; j++){
                        mat[i][j] = mat[i][j + 1];
                    }
                    mat[i][n - 1] = first;
                } else {
                    int last = mat[i][n - 1];
                    for(int j = n - 1; j > 0; j--){
                        mat[i][j] = mat[i][j - 1];
                    }
                    mat[i][0] = last;
                }
            }
        }
        
        return mat == original;
    }
};
