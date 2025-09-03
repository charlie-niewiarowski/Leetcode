class DetectSquares:

    def __init__(self):
        self.pointsCount = defaultdict(int)
        self.pts = []

    def add(self, point: List[int]) -> None:
        self.pointsCount[tuple(point)] += 1
        self.pts.append(point)

    def count(self, point: List[int]) -> int:
        res = 0
        px, py = point
        for x, y in self.pts:
            if (abs(py - y) != abs(px - x)) or px == x or py == y:
                continue
            
            res += self.pointsCount[(x, py)] * self.pointsCount[(px, y)]
        return res