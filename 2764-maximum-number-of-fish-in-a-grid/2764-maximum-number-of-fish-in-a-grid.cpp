class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int helper(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Boundary check and visited check
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j] == 1) {
            return 0;
        }

        visited[i][j] = 1;  // Mark the cell as visited

        int sum = grid[i][j]; // Add the value of the current cell
        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            sum += helper(grid, visited, new_i, new_j); // Recursive call
        }

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0)); // Correctly initialize the visited matrix

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && visited[i][j] == 0) { // Check for unvisited cells with fish
                    int count = helper(grid, visited, i, j);
                    result = max(result, count); // Update the maximum fish count
                }
            }
        }

        return result;
    }
};
