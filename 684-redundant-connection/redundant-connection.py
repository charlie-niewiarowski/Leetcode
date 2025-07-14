class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        disjoint = [i for i in range(n + 1)]
        rank = [1] * (n + 1)

        def find(n):
            if n == disjoint[n]:
                return disjoint[n]
            disjoint[n] = find(disjoint[n])
            return disjoint[n]
        
        def union(n1, n2):
            p1, p2 = find(n1), find(n2)
            if p1 == p2:
                return False

            if rank[p1] > rank[p2]:
                disjoint[p2] = p1
                rank[p1] += rank[p2]
            else:
                disjoint[p1] = p2
                rank[p2] += rank[p1]
            return True
        
        for x, y in edges:
            if not union(x, y):
                return [x, y]