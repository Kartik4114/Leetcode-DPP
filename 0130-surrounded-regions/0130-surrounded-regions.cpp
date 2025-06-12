class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};

    void helper(vector<vector<char>>& board, int row, int col, vector<vector<int>>& visited) {
        int m = board.size();
        int n = board[0].size();
        visited[row][col] = 1;

        for (auto& dir : directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            if (new_row >= 0 && new_col >= 0 && new_row < m && new_col < n
                && !visited[new_row][new_col] && board[new_row][new_col] == 'O') {
                helper(board, new_row, new_col, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Traverse top and bottom row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                helper(board, 0, j, visited);
            }
            if (board[m - 1][j] == 'O' && !visited[m - 1][j]) {
                helper(board, m - 1, j, visited);
            }
        }

        // Traverse left and right column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                helper(board, i, 0, visited);
            }
            if (board[i][n - 1] == 'O' && !visited[i][n - 1]) {
                helper(board, i, n - 1, visited);
            }
        }

        // Flip surrounded 'O' to 'X', and keep border-connected 'O' as is
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
