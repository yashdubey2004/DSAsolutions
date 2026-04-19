class Solution {
public:
    int sumation(vector<int>& weights) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }
        return sum;
    }

    int maximum(vector<int>& weights) {
        int maxi = 0;
        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }

    int daycheck(vector<int>& weights, int capacity) {
        int sum2 = 0;
        int count = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] + sum2 > capacity) {
                count++;
                sum2 = weights[i];
            } else {
                sum2 += weights[i];
            }
        }
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = maximum(weights);
        int high = sumation(weights);
        while (low <= high) {
            int mid = (low + high) / 2;
            int numberOfDays = daycheck(weights, mid);
            if (numberOfDays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
