// dp[steps_rem][pos] = # of ways to reach pos = 0 using exactly step_rem steps

class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1'000'000'007;
        arrLen = min(arrLen, steps);

        vector<vector<long long>> dp(steps + 1, vector<long long>(arrLen, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j < arrLen; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j < arrLen - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }

        return static_cast<int>(dp[steps][0] % MOD);
    }
};