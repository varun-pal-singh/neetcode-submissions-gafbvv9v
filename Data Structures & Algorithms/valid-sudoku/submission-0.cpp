class Solution {
private:
    int getBoxId(int row, int col) {
        // if (row <= 2) {
        //     if (col <= 2)       return 0;
        //     else if (col <= 5)  return 1;
        //     else if (col <= 8)  return 2;
        // }
        // else if (row <= 5) {
        //     if (col <= 2)       return 3;
        //     else if (col <= 5)  return 4;
        //     else if (col <= 8)  return 5;
        // }
        // else if (row <= 8) {
        //     if (col <= 2)       return 6;
        //     else if (col <= 5)  return 7;
        //     else if (col <= 8)  return 8;
        // }
        // return -1;
        return (row / 3) * 3 + (col / 3);
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<unordered_set<int>> row_sets(9), col_sets(9), box_sets(9);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                char ch = board[row][col];
                if (ch == '.') continue;

                int num = ch - '0';

                // row checking
                if (row_sets[row].find(num) != row_sets[row].end()) {
                    // cout << "RowBlock: row: " << row << ", col: " << col << "\n";
                    return false;
                }
                else {
                    row_sets[row].insert(num);
                }

                // col checking
                if (col_sets[col].find(num) != col_sets[col].end()) {
                    // cout << "colBlock: row: " << row << ", col: " << col << "\n";
                    return false;
                }
                else {
                    col_sets[col].insert(num);
                }

                // box checking
                int box_id = getBoxId(row, col);
                if (box_sets[box_id].find(num) != box_sets[box_id].end()) {
                    // cout << "boxBlock: row: " << row << ", col: " << col << "boxId: " << box_id << "\n";
                    return false;
                }
                else {
                    box_sets[box_id].insert(num);
                }
            }
        }
        return true;
    }
};
