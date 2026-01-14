class Solution {
public:
    void depth(vector<vector<int>>& image, int sr, int sc, int color, int ogcolor){
        int m = image.size();
        int n = image[0].size();

        if(sr < 0 || sr >= m || sc < 0 || sc >= n) return;
        if(image[sr][sc] != ogcolor) return;

        image[sr][sc] = color;

        depth(image, sr + 1, sc, color, ogcolor);
        depth(image, sr - 1, sc, color, ogcolor);
        depth(image, sr, sc + 1, color, ogcolor);
        depth(image, sr, sc - 1, color, ogcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc = image[sr][sc];
        if(oc == color) return image;
        depth(image, sr, sc, color, oc);
        return image;
    }
};
