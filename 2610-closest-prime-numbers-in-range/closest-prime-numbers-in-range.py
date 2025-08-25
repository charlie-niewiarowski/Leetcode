class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        def is_prime(number):
            if number < 2:
                return False
            if number == 2:
                return True
            if number % 2 == 0:  
                return False

            for i in range(3, int(math.sqrt(number)) + 1, 2):
                if number % i == 0:
                    return False
            return True
        
        lastPrime, res = -1, [0, float('inf')]
        for n in range(left, right + 1):
            if not is_prime(n):
                continue
            
            if lastPrime != -1 and res[1] - res[0] > n - lastPrime:
                res = [lastPrime, n]
            lastPrime = n
        return res if res != [0, float('inf')] else [-1, -1]