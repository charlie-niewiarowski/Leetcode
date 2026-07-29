class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }   

        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr{pq.top()};
            pq.pop();
            int time{curr[0]}, row{curr[1]}, col{curr[2]};

            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            if (visited[row][col]) {
                continue;
            }

            visited[row][col] = true;
            for (const auto [dr, dc] : directions) {
                if (!is_valid(visited, row + dr, col + dc)) {
                    continue;
                }

                int wait_time = ((grid[row + dr][col + dc] - time) % 2 == 0) ? 1 : 0;
                int next_time{std::max(grid[row + dr][col + dc] + wait_time, time + 1)};

                pq.push({next_time, row + dr, col + dc});
            }
        }

        return -1;
    }

private:
    bool is_valid(const vector<vector<bool>>& visited, const int r, const int c) {
        return r >= 0 && r < visited.size() && c >= 0 && c < visited[0].size() && !visited[r][c];
    }
};