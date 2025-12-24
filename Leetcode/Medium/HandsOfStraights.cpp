class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for(int i = 0; i < hand.size(); i++){
            freq[hand[i]]++;
        }

        sort(hand.begin(), hand.end());

        for(int i = 0; i < hand.size(); i++){
            if(freq.find(hand[i]) == freq.end()) continue;

            freq[hand[i]]--;
            if(freq[hand[i]] == 0){
                freq.erase(hand[i]);
            }

            for(int j = 1; j < groupSize; j++){
                int next = hand[i] + j;
                if(freq.find(next) == freq.end()){
                    return false;
                }
                freq[next]--;
                if(freq[next] == 0){
                    freq.erase(next);
                }
            }
        }
        return true;
    }
};
