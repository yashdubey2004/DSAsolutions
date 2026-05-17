class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for(int i = 0; i < events.size(); i++) {
            if(events[i] == "W") {
                counter++;
            }
            else if(events[i] == "WD" || events[i] == "NB") {
                score++;
            }
            else if(isdigit(events[i][0])) {
                score += stoi(events[i]);
            }
            if(counter == 10) break;
        }
        return {score, counter};
    }
};
