class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n = len(p)
        if n > len(s):
            return []
            
        solutionCount = {}
        for c in p:
            solutionCount[c] = solutionCount.get(c, 0) + 1
        
        winCount, satisfied = {}, 0
        for i in range(n):
            winCount[s[i]] = winCount.get(s[i], 0) + 1
            if s[i] in solutionCount and winCount[s[i]] == solutionCount[s[i]]:
                satisfied += 1
        
        res = []
        for i in range(len(s) - n):
            print(satisfied)
            if satisfied == len(solutionCount):
                res.append(i)
        
            winCount[s[i]] -= 1
            if s[i] in solutionCount and winCount[s[i]] == solutionCount[s[i]] - 1:
                satisfied -= 1

            winCount[s[i + n]] = winCount.get(s[i + n], 0) + 1
            if s[i + n] in solutionCount and winCount[s[i + n]] == solutionCount[s[i + n]]:
                satisfied += 1
        
        if satisfied == len(solutionCount):
            res.append(len(s) - n)
        
        return res
