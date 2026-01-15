class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hcount = 1;
        int fhcount = 1;
        for(int i = 0; i < hBars.size() - 1; i++){
            if(hBars[i] == hBars[i + 1] - 1){
                hcount++;
                if(hcount > fhcount){
                    fhcount = hcount;
                }
            }
            else{
                hcount = 1;
            }
        }
        int fvcount = 1;
        int vcount = 1;
        for(int i = 0; i < vBars.size() - 1; i++){
            if(vBars[i] == vBars[i + 1] - 1){
                vcount++;
                if(vcount > fvcount){
                    fvcount = vcount;
                }
            }
            else{
                vcount = 1;
            }
        }
        int len = min(fvcount + 1, fhcount + 1);
        return len * len;
    }
};
