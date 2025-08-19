class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        adj = collections.defaultdict(list)

        for i, (x, y) in enumerate(equations):
            adj[x].append((y, values[i]))
            adj[y].append((x, 1 / values[i]))
        
        res = []
        print(adj)
        for i, (x, y) in enumerate(queries):
            if x not in adj:
                res.append(-1)
                continue
            
            q = deque([(x, 1)])
            visited = set()
            found = False
            while q:
                n, val = q.popleft()
                visited.add(n)

                if n == y:
                    res.append(val)
                    found = True
                    break
                
                for num, multiplier in adj[n]:
                    if num not in visited:
                        q.append((num, val * multiplier))

            if not found:
                res.append(-1)
        return res