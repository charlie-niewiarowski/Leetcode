class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr = res = nums[0]
        for i in range(1, len(nums)):
            if curr < 0:
                curr = nums[i]
            else:
                curr += nums[i]
            res = max(res, curr)
        return res