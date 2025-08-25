class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        def primes():
            primes = [True] * (right + 1)
            primes[0] = primes[1] = False

            for n in range(2, int(math.sqrt(right)) + 1):
                if primes[n] == False:
                    continue
                
                for m in range(2 * n, right + 1, n):
                    primes[m] = False
            
            res = []
            for i in range(left, right + 1):
                if primes[i]:
                    res.append(i)
            return res
        
        diff, res = right - left + 1, [-1, -1]
        primes = primes()
        for i in range(len(primes) - 1):
            if primes[i + 1] - primes[i] < diff:
                diff = primes[i + 1] - primes[i]
                res = [primes[i], primes[i + 1]]    
        return res
