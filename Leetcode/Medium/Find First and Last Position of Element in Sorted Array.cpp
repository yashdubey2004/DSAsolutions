class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;

        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                int n = mid;
                int m = mid;

                while(n >= 0 && nums[n] == target){
                    n--;
                }

                while(m < nums.size() && nums[m] == target){
                    m++;
                }

                first = n + 1;
                last = m - 1;

                break;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return {first, last};
    }
};
