class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False
        
        totals = set()
        totals.add(0)
        target = sum(nums) // 2

        for i in range(len(nums) - 1, -1, -1):
            nextTotals = set()
            for t in totals:
                nextTotals.add(nums[i] + t)
                nextTotals.add(t)
            totals = nextTotals

            if target in totals:
                return True
        return False