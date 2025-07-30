class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(set)
        in_degree = defaultdict(int)
        for u, v in prerequisites:
            in_degree[v] += 1
            graph[u].add(v)
        
        q = deque()
        for vertex in range(numCourses):
            if in_degree[vertex] == 0:
                q.append(vertex)
        
        finish = 0
        while (q):
            curr = q.popleft()
            finish += 1

            for nei in graph[curr]:
                in_degree[nei] -= 1
                if in_degree[nei] == 0:
                    q.append(nei)
                
        return finish == numCourses