class Solution {
private:
    int rows, cols;
    vector<pair<int, int>> directions;
    vector<vector<bool>> visited;

    bool borders(int r, int c) {
        return r == 0 || c == 0 || r == rows - 1 || c == cols - 1;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0 || visited[r][c]) return 0;

        visited[r][c] = true;
        int res = 1;
        for (auto& [dr, dc] : directions) {
            res += dfs(grid, r + dr, c + dc);
        }
        return res;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        rows = grid.size(); cols = grid[0].size();
        directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        int land = 0, borderLand = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                land += grid[r][c];
                if (grid[r][c] == 1 && !visited[r][c] && borders(r, c)) {
                    borderLand += dfs(grid, r, c);
                }
            }
        }

        return land - borderLand;
    }
};