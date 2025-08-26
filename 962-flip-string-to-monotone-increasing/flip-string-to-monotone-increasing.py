class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        dp = [[0] * 2 for _ in range(n + 1)]

        for i in range(n - 1, -1, -1):
            if s[i] =='0':
                dp[i][0] = 1 + dp[i + 1][0]
                dp[i][1] = min(1 + dp[i + 1][0], dp[i + 1][1])
            else:
                dp[i][0] = dp[i + 1][0]
                dp[i][1] = min(1 + dp[i + 1][1], dp[i + 1][0])

        return dp[0][1]