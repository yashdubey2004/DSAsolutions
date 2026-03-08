class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int idx = -1, mini = INT_MAX;
        for(int i = 0; i < capacity.size(); i++){
            if(capacity[i] >= itemSize){
                if(capacity[i] - itemSize < mini){
                    mini = capacity[i] - itemSize;
                    idx = i;
                }
            }
        }
        return idx;
    }
};
