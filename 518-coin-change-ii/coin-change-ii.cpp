class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int LIMIT = INT_MAX;
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int c : coins) {
            for (int a = c; a <= amount; ++a) {
                dp[a] += dp[a - c];
                if (dp[a] > LIMIT) dp[a] = LIMIT;
            }
        }

        return dp[amount];
    }
};