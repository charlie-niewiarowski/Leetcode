class Solution {
private:
    int rows, cols;
    vector<pair<int, int>> directions;

    int count_mines(vector<vector<char>>& board, int r, int c) {
        int res = 0;
        for (auto& [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'M') 
                ++res;
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'E') return;

        int mines = count_mines(board, r, c);
        if (mines > 0) {
            board[r][c] = static_cast<char>('0' + mines);
        }
        else {
            board[r][c] = 'B';
            for (auto& [dr, dc] : directions) {
                dfs(board, r + dr, c + dc);
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        rows = board.size(), cols = board[0].size();
        directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

        int r = click[0], c = click[1];
        char& ch = board[r][c];


        if (ch == 'M') {
            ch = 'X';
        }
        else {
            dfs(board, r, c);
        }

        return board;
    }
};