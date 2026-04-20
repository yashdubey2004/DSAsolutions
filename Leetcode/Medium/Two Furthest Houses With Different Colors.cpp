class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left = 0, right = colors.size() - 1;
        while(right >= 0 && colors[left] == colors[right]){
            right--;
        }
        int res = right - left;
        left = 0, right = colors.size() - 1;
        while(left < colors.size() && colors[left] == colors[right]){
            left++;
        }
        res = max(res, right - left);
        return res;
    }
};
