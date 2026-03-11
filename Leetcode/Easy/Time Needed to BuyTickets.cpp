class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        int i = 0;
        while(tickets[k] > 0){
            if(tickets[i] == 0) {
                i = (i + 1) % tickets.size();
                continue;
            }
            tickets[i] -= 1;
            i = (i + 1) % tickets.size();
            count++;
        }
        return count;
    }
};
