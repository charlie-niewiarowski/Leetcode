class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        in_degree = [0] * numCourses
        
        for u, v in prerequisites:
            graph[u].append(v)
            in_degree[v] += 1

        queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
        topo_order = []

        while queue:
            node = queue.popleft()
            topo_order.append(node)

            for neighbor in graph[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        if len(topo_order) == numCourses:
            return topo_order[::-1]
        else:
            return []  