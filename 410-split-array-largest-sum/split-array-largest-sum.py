class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        l, r = max(nums), sum(nums)

        res = 0
        def canPartition(target):
            currSum, currSubs = 0, 1
            for num in nums:
                if currSum + num > target:
                    currSum = num
                    currSubs += 1
                else:
                    currSum += num
            return currSubs <= k

        while l <= r:
            m = (l + r) // 2
            if canPartition(m):
                res = m
                r = m - 1
            else:
                l = m + 1
        return res