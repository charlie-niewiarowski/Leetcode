class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = defaultdict(set)
        for u, v, time in times:
            adj[u].add((v, time))
        
        visit, pq = set(), [(0 ,k)]
        res = 0
        while pq:
            time, u = heapq.heappop(pq)
            if u in visit:
                continue
            visit.add(u)
            res = time

            for v, time2 in adj[u]:
                if v not in visit:
                    heapq.heappush(pq, (time + time2, v))
        
        return res if len(visit) == n else -1