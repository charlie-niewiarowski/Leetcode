class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        ROWS, COLS = len(s) + 1, len(t) + 1
        dp = [[0] * COLS for _ in range(ROWS)]
        
        for r in range(len(dp)):
            dp[r][COLS - 1] = 1

        for r in range(ROWS - 2, -1, -1):
            for c in range(COLS - 2, -1, -1):
                dp[r][c] = dp[r + 1][c]
                if s[r] == t[c]:
                    dp[r][c] += dp[r + 1][c + 1]
        
        return dp[0][0]