class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = INT_MIN;
        while(left < height.size() && right >= 0 && left < right){
            int curr = min(height[left], height[right]) * (right - left);
            res = max(curr, res);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return res;
    }
};
