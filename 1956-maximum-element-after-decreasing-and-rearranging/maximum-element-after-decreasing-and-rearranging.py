class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        prev = 0
        for i in range(len(arr)):
            if abs(arr[i] - prev) > 1:
                arr[i] = prev + 1
            prev = arr[i]
        return prev
            
            