class Solution {
public:
    double dp[101][101];

    double champagneTower(int poured, int query_row, int query_glass) {
        memset(dp, 0, sizeof(dp));

        dp[0][0] = poured;

        for(int i = 0; i <= query_row; i++){
            for(int j = 0; j <= i; j++){

                if(dp[i][j] > 1){
                    double overflow = dp[i][j] - 1;
                    dp[i][j] = 1;

                    dp[i + 1][j] += overflow / 2;
                    dp[i + 1][j + 1] += overflow / 2;
                }
            }
        }

        if(dp[query_row][query_glass] > 1)
            return 1.0;

        return dp[query_row][query_glass];
    }
};
