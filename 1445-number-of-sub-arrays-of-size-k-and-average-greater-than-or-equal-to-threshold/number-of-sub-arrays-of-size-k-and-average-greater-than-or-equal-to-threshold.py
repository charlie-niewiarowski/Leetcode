class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        res = 0
        curr, target = sum(arr[0 : k]), threshold * k

        for i in range(len(arr) - k + 1):
            print(i, curr)
            if curr >= target:
                res += 1

            curr -= arr[i]
            if i + k < len(arr):
                curr += arr[i + k]
        
        return res