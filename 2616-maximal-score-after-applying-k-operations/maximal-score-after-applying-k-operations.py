class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        heap = [-x for x in nums]
        heapq.heapify(heap)

        res = 0
        for _ in range(k):
            curr = -heapq.heappop(heap)
            res += curr
            heapq.heappush(heap, -ceil(curr / 3))
            
        return res