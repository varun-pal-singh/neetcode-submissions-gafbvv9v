class Solution {
private:
    int ROWS = 0, COLS = 0;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool is_not_valid_idx(vector<vector<char>> &grid, vector<vector<bool>> &visited, const int i, const int j) {
      return (std::min(i, j) < 0 || i == ROWS || j == COLS || grid[i][j] == '0' || visited[i][j]);
    }

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, const int row, const int col) {
        if (is_not_valid_idx(grid, visited, row, col)) {
            return;
        }
        visited[row][col] = true;

        for (auto [i, j] : dirs) {
            dfs(grid, visited, row + i, col + j);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
       ROWS = grid.size(); 
       if (ROWS == 0)   return 0;
       COLS = grid[0].size();

       vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
       int islands = 0;
       for (int r = 0; r < ROWS; r++) {
           for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1' && !visited[r][c]) {
                    dfs(grid, visited, r, c);
                    islands ++;
                }
           }
       } 
    return islands;
    }
};
