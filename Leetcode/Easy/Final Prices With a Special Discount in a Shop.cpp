class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer;
        bool check = true;
        for(int i = 0; i < prices.size(); i++){
            check = true;
            for(int j = i + 1; j < prices.size(); j++){
                if(prices[j] <= prices[i]){
                    answer.push_back(prices[i] - prices[j]);
                    check = false;
                    break;
                }
            }
            if(check == true){
                answer.push_back(prices[i]);
            }
        }
        //answer.push_back(prices[prices.size() - 1]);
        return answer;
    }
};
