class Solution {
private:
    int ROWS = 0, COLS = 0;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int calculateParameterBFS(const vector<vector<int>>& grid,
                              std::vector<std::vector<bool>>& visited,
                              const int row, const int col) 
    {
        if (visited[row][col])
            return 0;
        visited[row][col] = true;
        std::queue<std::pair<int, int>> que;
        que.push({row, col});
        int parameter = 0;

        while (que.size() > 0) {
            int size = que.size();
            while (size-- > 0) {
                auto [r, c] = que.front();
                que.pop();
                for (auto [i, j] : dirs) {
                    int r1 = r + i, c1 = c + j;
                    if (std::min(r1, c1) < 0 || r1 == ROWS || c1 == COLS ||
                        grid[r1][c1] == 0) {
                        parameter += 1;
                    } 
                    else if (!visited[r1][c1]) {
                        visited[r1][c1] = true;
                        que.push({r1, c1});
                    }
                }
            }
        }

        return parameter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ROWS = grid.size();
        if (ROWS == 0)
            return -1;
        COLS = grid[0].size();
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        int parameter = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    // parameter += calculateParameterBFS(grid, visited, r, c);
                    return calculateParameterBFS(grid, visited, r, c);
                }
            }
        }

        return parameter;
    }
};