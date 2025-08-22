class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        degrees = [0] * n
        for u, v in roads:
            degrees[u] += 1
            degrees[v] += 1
        
        importance, res = 1, 0
        for deg in sorted(degrees):
            res += importance * deg
            importance += 1
        return res