class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr, res = 0, nums[0]
        for num in nums:
            if curr < 0:
                curr = 0
            curr += num
            res = max(res, curr)
        return res