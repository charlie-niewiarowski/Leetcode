# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountainArr: 'MountainArray') -> int:
        l, r = 1, mountainArr.length() - 1

        while l <= r:
            m = (l + r) // 2
            curr, prev, nxt = mountainArr.get(m), mountainArr.get(m - 1), mountainArr.get(m + 1)

            if curr > prev and curr > nxt:
                break
            elif curr > prev and curr < nxt:
                l = m + 1
            else:
                r = m - 1
        peak = m
        
        l, r = 0, peak
        while l <= r:
            m = (l + r) // 2
            curr = mountainArr.get(m)
            if curr == target:
                return m
            elif curr < target:
                l = m + 1
            else:
                r = m - 1
        
        l, r = peak, mountainArr.length() - 1
        while l <= r:
            m = (l + r) // 2
            curr = mountainArr.get(m)
            if curr == target:
                return m
            elif curr > target:
                l = m + 1
            else: 
                r = m - 1
        
        return -1
        