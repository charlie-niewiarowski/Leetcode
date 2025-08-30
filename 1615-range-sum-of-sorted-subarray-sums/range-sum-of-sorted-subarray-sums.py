class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        res = []

        def backtrack(i, curr):
            if i == n:
                return (curr)
            
            backtrack(i + 1, curr + nums[i])
            res.append(curr + nums[i])
        
        for i in range(n):
            backtrack(i, 0)
        
        res.sort()
        return sum(res[left - 1: right]) % (10**9 + 7)