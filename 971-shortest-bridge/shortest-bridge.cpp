class Solution {
private:
    vector<vector<int>> grid;
    vector<pair<int, int>> directions;
    int rows;
    int cols;

    void dfs(int r, int c, set<pair<int, int>>& island) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0 || island.contains({r, c})) return;

        island.insert({r, c});
        for (const auto& [dr, dc] : directions) {
            dfs(r + dr, c + dc, island);
        }
    }

    int bfs(const set<pair<int, int>>& start, const set<pair<int, int>>& target) {
        deque<pair<int, int>> q;
        set<pair<int, int>> visited;
        for (const auto& point : start) {
            q.push_back(point);
            visited.insert(point);
        }

        int res = 0;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front(); q.pop_front();
                cout << r << " " << c << " " << res << "\n";
                if (target.contains({r, c})) return res - 1; 

                for (const auto& [dr, dc] : directions) {
                    if (r + dr >= 0 && c + dc >= 0 && r + dr < rows && c + dc < cols && !visited.contains({r + dr, c + dc})) {
                        visited.insert({r + dr, c + dc});
                        q.push_back({r + dr, c + dc});
                    }
                }
            }

            ++res;
        }

        return -1;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        this->grid = grid;
        directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        rows = grid.size();
        cols = grid[0].size();

        set<pair<int, int>> islandOne;
        set<pair<int, int>> islandTwo;



        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    if (islandOne.empty()) dfs(r, c, islandOne);
                    else if (!islandOne.contains({r, c})) dfs(r, c, islandTwo);
                }
            }
        }
    

        if (islandOne.size() < islandTwo.size()) {
            return bfs(islandOne, islandTwo);
        }

        return bfs(islandTwo, islandOne);
    }
};