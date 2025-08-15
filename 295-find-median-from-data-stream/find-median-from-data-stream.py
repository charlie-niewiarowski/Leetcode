class MedianFinder:

    def __init__(self):
        # Heap for smallest half and largest half
        self.smaller, self.larger = [], []

    def addNum(self, num: int) -> None:
        if self.larger and num > self.larger[0]:
            heapq.heappush(self.larger, num)
        else:
            heapq.heappush(self.smaller, -1 * num)
        
        if len(self.larger) > len(self.smaller) + 1:
            val = heapq.heappop(self.larger)
            heapq.heappush(self.smaller, val * -1)
        elif len(self.smaller) > len(self.larger) + 1:
            val = heapq.heappop(self.smaller) * -1
            heapq.heappush(self.larger, val)


    def findMedian(self) -> float:
        if len(self.larger) > len(self.smaller):
            return self.larger[0]
        elif len(self.smaller) > len(self.larger):
            return -1 * self.smaller[0]
        else:
            return (self.smaller[0] * -1 + self.larger[0]) / 2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()