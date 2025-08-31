class Solution:
    def myPow(self, x: float, n: int) -> float:
        def myPow_(x, n):
            if x == 0:
                return 0
            if n == 0:
                return 1
            
            res = myPow_(x * x, n // 2)
            return res * x if n % 2 else res
        
        res = myPow_(x, abs(n))
        return res if n >= 0 else 1 / res