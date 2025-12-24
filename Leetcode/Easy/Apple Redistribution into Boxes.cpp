class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int cap = 0;
        for(int i = 0; i < apple.size(); i++){
            cap += apple[i];
        }
        sort(capacity.begin(), capacity.end());
        int count = 0, sum = 0, i = capacity.size() - 1;
        while(i >= 0 && sum < cap){
            sum += capacity[i];
            count++;
            i--;
        }
        return count;
    }
};
