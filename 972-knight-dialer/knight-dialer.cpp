class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> moves{
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        vector<long long> dp(10, 1);
        for (int i = 2; i <= n; ++i) {
            vector<long long> next(10, 0);

            for (int j = 0; j <= 9; ++j) {
                for (const int& nei : moves[j]) {
                    next[nei] = (next[nei] + dp[j]) % MOD;
                }
            }

            dp.swap(next);
        }

        long long res = 0;
        for (const int& x : dp) {
            res = (res + x) % MOD;
        }

        return int(res);
    }
};