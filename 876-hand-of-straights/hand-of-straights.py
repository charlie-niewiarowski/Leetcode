class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand.sort()
        freq = collections.defaultdict(int)

        for n in hand:
            freq[n] += 1
        
        for n in hand:
            print("n:", n, freq[n])
            if freq[n] == 0:
                continue
            
            for m in range(n, n + groupSize):
                if freq[m] == 0:
                    return False
                freq[m] -= 1 

        return True