class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>a, b,c;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 3 == 0){
                a.push_back(nums[i]);
            }
            else if(nums[i] % 3 == 1){
                b.push_back(nums[i]);
            }
            else{
                c.push_back(nums[i]);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int ans = 0;
        if(a.size() >= 3){
            int sum = a[a.size() - 1] + a[a.size() - 2] + a[a.size() - 3];
            if(sum > ans){
                ans = sum;
            }
        }
        if(b.size() >= 3){
            int sum = b[b.size()- 1] + b[b.size() - 2] + b[b.size() - 3];
            if(sum > ans){
                ans = sum;
            }
        }
        if(c.size() >= 3){
            int sum = c[c.size() - 1] + c[c.size() - 2] + c[c.size() - 3];
            if(sum > ans){
                ans = sum;
            }
        }
        if(a.size() >= 1 && b.size() >= 1 && c.size() >= 1){
            int sum = a[0] + b[0] + c[0];
            if(sum > ans){
                ans = sum;
            }
            sum = a[a.size() - 1] + b[b.size() - 1] + c[c.size() - 1];
            if(sum > ans){
                ans = sum;
            }
        }
        return ans;
    }
};
