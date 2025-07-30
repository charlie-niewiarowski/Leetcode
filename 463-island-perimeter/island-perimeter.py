class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        res = 0
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    for dr, dc in directions:
                        if r + dr < 0 or r + dr >= ROWS or c + dc < 0 or c + dc >= COLS or grid[r + dr][c + dc] == 0:
                            res += 1
        return res
