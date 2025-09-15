class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        if (obstacleGrid[M - 1][N - 1] == 1) return 0;

        vector<vector<unsigned int>> dp(M + 1, vector<unsigned int>(N + 1, 0));
        dp[M - 1][N - 1] = 1;

        for (int r = M - 1; r >= 0; --r) {
            for (int c = N - 1; c >= 0; --c) {
                if (obstacleGrid[r][c] == 0) {
                    dp[r][c] += dp[r + 1][c] + dp[r][c + 1];
                }
            }
        }

        return dp[0][0];
    }
};