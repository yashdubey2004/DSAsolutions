class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size() - 1 ; i++){
            int one = abs(points[i + 1][0] - points[i][0]);
            int two = abs(points[i + 1][1] - points[i][1]);
            int ans = max(one, two);
            res += ans;
        }
        return res;
    }
};
