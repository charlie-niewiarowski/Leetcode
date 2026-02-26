class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = accumulate(stones.begin(), stones.end(), 0);
        int half = total / 2;

        vector<vector<int>> dp(n + 1, vector<int>(half + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int s = 0; s <= half; ++s) {
                int stone = stones[i - 1];

                if (s >= stone) {
                    dp[i][s] = max(dp[i - 1][s], dp[i - 1][s - stone] + stone);
                }
                else {
                    dp[i][s] = dp[i - 1][s];
                }
            }
        }

        return total - 2 * dp[n][half];
    }
};