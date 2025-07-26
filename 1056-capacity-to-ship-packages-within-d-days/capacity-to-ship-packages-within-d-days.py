class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l, r = max(weights), sum(weights)

        def canShip(cap):
            ships, currTotal = 1, 0
            for w in weights:
                if w + currTotal > cap:
                    ships += 1
                    currTotal = w
                else:
                    currTotal += w
            return ships <= days
        
        res = r
        while l <= r:
            cap = (l + r) // 2
            if canShip(cap):
                res = min(res, cap)
                r = cap - 1
            else:
                l = cap + 1
        
        return res