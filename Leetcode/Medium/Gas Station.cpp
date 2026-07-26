class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total = 0;
        int currtank = 0;

        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            currtank += gas[i] - cost[i];

            if(currtank < 0){
                start = i + 1;
                currtank = 0;
            }
        }

        if(total < 0) return -1;
        return start;
    }
};
