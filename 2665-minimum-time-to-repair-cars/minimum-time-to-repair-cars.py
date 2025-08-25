class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        def canRepair(time):
            repairedCars = 0
            for r in ranks:
                repairedCars += int(math.sqrt(time / r))
            return repairedCars >= cars
        
        l, r = 0, sum(ranks) * cars * cars
        res = r
        while l <= r:
            m = (l + r) // 2
            if canRepair(m):
                res = m
                r = m - 1
            else:
                l = m + 1

        return res