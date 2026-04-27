class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long rightsum = 0;
        for(int i = 0; i < nums.size(); i++){
            rightsum += nums[i];
        }
        long long leftsum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && i != nums.size() - 1 && nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
                leftsum += nums[i];
                break;
            }
            leftsum += nums[i];
            rightsum -= nums[i];
        }
        if(leftsum > rightsum) return 0;
        else if(rightsum > leftsum) return 1;
        return -1;
    }
};
