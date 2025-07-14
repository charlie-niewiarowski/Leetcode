class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        cuboids = sorted([sorted(cube) for cube in cuboids])
        n = len(cuboids)
        dp = [0] * n
        print(cuboids)
        
        for i in range(n):
            maxHeight = cuboids[i][2]
            for j in range(i):
                if cuboids[i][0] >= cuboids[j][0] and cuboids[i][1] >= cuboids[j][1] and cuboids[i][2] >= cuboids[j][2]:
                    maxHeight = max(maxHeight, cuboids[i][2] + dp[j])
            dp[i] = maxHeight
        return max(dp)
            