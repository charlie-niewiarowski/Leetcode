class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < i + 1; ++j) {
                int square = j * j;
                if (i - square < 0) break;

                dp[i] = std::min(dp[i], 1 + dp[i - square]); 
            }
        }
        
        return dp[n];
    }
};