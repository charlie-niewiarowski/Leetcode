class Solution:
    def solve(self, board: List[List[str]]) -> None:
        ROWS, COLS = len(board), len(board[0])
        directions = [[1,0],[-1,0],[0,1],[0,-1]]
        visited = set()

        def bfs(r, c):
            q = deque([(r, c)])
            region = [(r, c)]
            visited.add((r, c))
            touches_border = (r == 0 or c == 0 or r == ROWS - 1 or c == COLS - 1)

            while q:
                cr, cc = q.popleft()

                for dr, dc in directions:
                    nr, nc = cr + dr, cc + dc
                    if (
                        0 <= nr < ROWS and
                        0 <= nc < COLS and
                        board[nr][nc] == "O" and
                        (nr, nc) not in visited
                    ):
                        q.append((nr, nc))
                        region.append((nr, nc))
                        visited.add((nr, nc))
                        if nr == 0 or nc == 0 or nr == ROWS - 1 or nc == COLS - 1:
                            touches_border = True
            if not touches_border:
                for rr, cc in region:
                    board[rr][cc] = "X"

        
        for r in range(1, ROWS - 1):
            for c in range(1, COLS - 1):
                if board[r][c] == "O" and (r, c) not in visited:
                    bfs(r, c)