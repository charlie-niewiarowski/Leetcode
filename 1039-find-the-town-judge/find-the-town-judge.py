class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 1: 
            return 1

        delta = defaultdict(int)
        for u, v in trust:
            delta[u] -= 1
            delta[v] += 1
        
        for vertex in delta:
            if delta[vertex] == n - 1:
                return vertex
        
        return -1