class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 1);
        
        for (int nodes{2}; nodes <= n; ++nodes) {
            int total{};
            for (int root{1}; root <= nodes; ++root) {
                total += dp[root - 1] * dp[nodes - root];
            }
            dp[nodes] = total;
        }

        return dp[n];
    }
};