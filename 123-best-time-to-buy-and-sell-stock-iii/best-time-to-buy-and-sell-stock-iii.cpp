class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, INT_MIN)));
        dp[0][0][0] = 0;
        dp[0][1][0] = -1 * prices[0];

        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][0][j] = dp[i - 1][0][j];
                if (j > 0 && dp[i - 1][1][j - 1] != INT_MIN) dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j - 1] + prices[i]);

                dp[i][1][j] = dp[i - 1][1][j];
                if (dp[i - 1][0][j] != INT_MIN) dp[i][1][j] = max(dp[i][1][j], dp[i - 1][0][j] - prices[i]);

                res = max(res, dp[i][0][j]);
            }
        }

        return res;
    }
};