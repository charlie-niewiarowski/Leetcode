class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        def canReach(m):
            nonlocal ROWS, COLS
            q = deque([(0, 0)])
            visited = {(0, 0)}

            while q:
                r, c = q.popleft()
                if (r, c) == (ROWS - 1, COLS - 1):
                    return True
                
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if not (nr < 0 or nr >= ROWS or nc < 0 or nc >= COLS or (nr, nc) in visited or grid[nr][nc] > m):
                        q.append((nr, nc))
                        visited.add((nr, nc))

            return False

        maxVal = max(max(row) for row in grid)
        l, r = max(grid[0][0], grid[ROWS - 1][COLS - 1]), maxVal
        res = r
        while l <= r:
            m = (l + r) // 2
            
            if canReach(m):
                res = m
                r = m - 1
            else:
                l = m + 1
        
        return res