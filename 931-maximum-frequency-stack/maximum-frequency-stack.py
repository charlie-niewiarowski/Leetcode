class FreqStack:
    def __init__(self):
        self.counts = {} # to track each values count
        self.stacks = {} # to track each count's values (in order)
        self.maxCount = 0 # to easily lookup the maximum values

    def push(self, val: int) -> None:
        self.counts[val] = 1 + self.counts.get(val, 0)
        
        if self.counts[val] >self. maxCount:
            self.maxCount = max(self.maxCount, self.counts[val])
            self.stacks[self.counts[val]] = []
        
        self.stacks[self.counts[val]].append(val)


    def pop(self) -> int:
        res = self.stacks[self.maxCount].pop()
        self.counts[res] -= 1

        if not self.stacks[self.maxCount]:
            self.maxCount -= 1

        return res


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()