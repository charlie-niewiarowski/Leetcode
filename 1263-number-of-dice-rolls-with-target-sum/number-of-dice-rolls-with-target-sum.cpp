/*
    dp[i][j] represents number of ways to have a rolling_sum of j, rolling i die
    from p = i - k, ..., i - 1, dp[i][j] += dp[i - 1][p];
    base case p = 1, ..., k, dp[0][p] = 1;
    return dp[n - 1][target]
*/  

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(target + 1, 0));
        for (int i = 1; i <= k && i <= target; ++i) dp[0][i] = 1;

        for (int i = 1; i < n; ++i) {
            if (i > target) break;

            for (int j = i + 1; j <= target; ++j) {
                for (int l = max(1, j - k); l < j; ++l) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][l]) % MOD;
                }
            }
        }

        return static_cast<int>(dp[n - 1][target] % MOD);
    }
};