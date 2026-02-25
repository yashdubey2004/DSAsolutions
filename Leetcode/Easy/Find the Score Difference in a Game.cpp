class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        bool firstplay = true;
        int count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1){
                if(firstplay) firstplay = false;
                else firstplay = true;
            }
            if(i % 6 == 5){
                if(firstplay) firstplay = false;
                else firstplay = true;
            }
            if(firstplay){
                count1 += nums[i];
            }
            else if(!firstplay){
                count2 += nums[i];
            }            
        }
        return count1 - count2;
    }
};
