class Solution {
    int ROWS = 0, COLS = 0;
    
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool is_valid_idx(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>> &visited,
                      const int row, const int col) {
        return std::min(row, col) >= 0 && row < ROWS && col < COLS && !visited[row][col] &&
               grid[row][col] == 1;
    }

    int dfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>> &visited,
            const int row, const int col) {
        if (!is_valid_idx(grid, visited, row, col)) {
            return 0;
        }

        visited[row][col] = true;
        int area = 1;
        for (auto [r, c] : dirs) {
            area += dfs(grid, visited, row + r, col + c);
        }
        return area;
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size(); if (ROWS == 0)  return 0;
        COLS = grid[0].size();
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        int max_area = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    max_area = std::max(max_area, dfs(grid, visited, r, c));
                }
            }
        }
        return max_area;
    }
};
