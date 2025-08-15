class Solution:
    def minWindow(self, s: str, t: str) -> str:
        letterCount, solutionCount = {}, {}

        for c in t:
            solutionCount[c] = 1 + solutionCount.get(c, 0)
        
        l, r = 0, 0
        satisfied, required = 0, len(solutionCount)
        res = ""

        while r < len(s):
            # Grow until satisfied is required
            while r < len(s) and satisfied < required:
                if s[r] in solutionCount:
                    letterCount[s[r]] = 1 + letterCount.get(s[r], 0)
                    if letterCount[s[r]] == solutionCount[s[r]]:
                        satisfied += 1
                r += 1

            # Shrink back until satisfied is not required
            while l < r and satisfied >= required:
                if not res or r - l < len(res):
                    res = s[l:r]
                if s[l] in solutionCount:
                    letterCount[s[l]] -= 1
                    if letterCount[s[l]] < solutionCount[s[l]]:
                        satisfied -= 1
                l += 1
        
        return res