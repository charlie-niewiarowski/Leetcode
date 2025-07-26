class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, sum(piles)
        totalHrs = r

        def canEat(k):
            hrs = 0
            for p in piles:
                timeToEat = math.ceil(p / k)
                hrs += timeToEat
            return hrs <= h

        k = r
        while l <= r:
            rate = (l + r) // 2
            if canEat(rate):
                k = rate
                r = rate - 1
            else:
                l = rate + 1
        return k