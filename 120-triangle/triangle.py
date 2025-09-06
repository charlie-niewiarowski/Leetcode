class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        h = len(triangle)
        dp = [[0] * (i + 1) for i in range(h + 1)]

        for r in range(h - 1, -1, -1):
            for c in range(len(triangle[r])):
                dp[r][c] = triangle[r][c] + min(dp[r + 1][c], dp[r + 1][c + 1])
        
        return dp[0][0]