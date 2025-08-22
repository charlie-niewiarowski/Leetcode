class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        zeros = ones = res = 0
        differenceToIndex = {}

        for i, n in enumerate(nums):
            if n == 0:
                zeros += 1
            else:
                ones += 1
            
            if (ones - zeros) not in differenceToIndex:
                differenceToIndex[ones - zeros] = i
            
            if ones == zeros:
                res = ones + zeros
            else:
                idx = differenceToIndex[ones - zeros]
                res = max(res, i - idx)
        
        return res