class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr_max = prices[n - 1], profit = 0;

        for (int i{n - 2}; i >= 0; --i) {
            int diff = curr_max - prices[i];
            if (diff > 0) {
                profit += diff;
            }

            curr_max = prices[i];
        }

        return profit;
    }
};