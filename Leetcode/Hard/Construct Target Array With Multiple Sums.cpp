class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(int x : target){
            pq.push(x);
            sum += x;
        } 
        while(true){
            long long largest = pq.top();
            pq.pop();
            long long rem = sum - largest;
            if(rem == 1 || largest == 1) return true;
            if(rem == 0 || rem >= largest) return false;
            int prev = largest % rem;
            if(prev == 0) return false;
            pq.push(prev);
            sum = rem + prev;
        }
    }
};
