class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        remainder_idx = {0: -1}
        prefix_sum = 0

        for i, num in enumerate(nums):
            prefix_sum += num
            prefix_sum %= k

            if prefix_sum in remainder_idx:
                if i - remainder_idx[prefix_sum] > 1:
                    return True
            else:
                remainder_idx[prefix_sum] = i
        return False
        
