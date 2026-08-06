class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        const vector<std::pair<int, int>> directions{
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        deque<vector<int>> free_queue, blocked_queue;
        vector<vector<int>> visited(rows, vector<int>(cols, std::numeric_limits<int>::max()));

        free_queue.push_back({0, 0, 0});
        visited[0][0] = 0;

        for (;;) {
            while (!free_queue.empty()) {
                auto top = free_queue.front();
                int r = top[0], c = top[1], num_obstacles = top[2];
                free_queue.pop_front(); 

                if (r == rows - 1 && c == cols - 1) {
                    return num_obstacles;
                }

                for (auto [dr, dc] : directions) {
                    int next_row = r + dr, next_col = c + dc;
                    if (should_visit(next_row, next_col, num_obstacles, grid, visited)) {
                        if (grid[next_row][next_col] == 0) {
                            free_queue.push_back({next_row, next_col, num_obstacles});
                        }
                        else {
                            blocked_queue.push_back({next_row, next_col, num_obstacles + 1});
                        }
                    }
                }
            }

            while (free_queue.empty() && !blocked_queue.empty()) {
                auto top = blocked_queue.front();
                int r = top[0], c = top[1], num_obstacles = top[2];
                blocked_queue.pop_front(); 

                for (auto [dr, dc] : directions) {
                    int next_row = r + dr, next_col = c + dc;
                    if (should_visit(next_row, next_col, num_obstacles, grid, visited)) {
                        if (grid[next_row][next_col] == 0) {
                            free_queue.push_back({next_row, next_col, num_obstacles});
                        }
                        else {
                            blocked_queue.push_back({next_row, next_col, num_obstacles + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }

private:
    int rows, cols;

    bool should_visit(int r, int c, int num_obstacles, const vector<vector<int>>& grid, vector<vector<int>>& visited) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }

        if (grid[r][c] == 1) {
            ++num_obstacles;
        }

        if (visited[r][c] > num_obstacles) {
            visited[r][c] = num_obstacles;
            return true;
        }

        return false;
    }
};