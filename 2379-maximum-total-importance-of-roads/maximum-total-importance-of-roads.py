class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        degrees = [[0, i] for i in range(n)]
        for u, v in roads:
            degrees[u][0] += 1
            degrees[v][0] += 1
        
        importance = [0] * n
        degrees.sort()
        for i, (deg, node) in enumerate(degrees):
            importance[node] = i + 1
        
        res = 0
        for u, v in roads:
            res += importance[u] + importance[v]
        return res
        