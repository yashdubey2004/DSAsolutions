class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int total_even = 0, total_odd = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0) total_even += nums[i];
            else total_odd += nums[i];
        }
        int count  = 0;
        int evenleft = 0, evenright = total_even, oddleft = 0, oddright = total_odd;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0) evenright -= nums[i];
            else evenleft -= nums[i];

            int neweven = evenleft + oddright;
            int newodd = oddleft + evenright;

            if(neweven == newodd) count++;

            if(i % 2 == 0) evenleft += nums[i];
            else oddleft += nums[i];
        }
        return count;
    }
};
