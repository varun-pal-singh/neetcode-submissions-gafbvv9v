class NumMatrix {
private:
    vector<vector<int>> prefixMat;
    int rows = 0, cols = 0;


    void print() {
        int rows = prefixMat.size();
        int cols = prefixMat[0].size();

        for (int i = 0; i < rows; i++) {
            std::cout << "[ " ;
            for (int j = 0; j < cols; j++) {
                std::cout << prefixMat[i][j] << ", ";
            }
            std::cout << "]\n";
        }
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
                                            // : rows(matrix.size()),
                                            //  cols(matrix[0].size()),
                                            //  prefixMat(rows, vector<int>(cols, 0)) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefixMat.resize(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int top     = (i > 0) ? prefixMat[i - 1][j] : 0;
                int left    = (j > 0) ? prefixMat[i][j - 1] : 0;
                int topLeft = (i > 0 && j > 0) ? prefixMat[i - 1][j - 1] : 0;
                prefixMat[i][j] = matrix[i][j] + top + left - topLeft;
            }
        }

        // print();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int topSum      = (row1 > 0) ? prefixMat[row1 - 1][col2] : 0;
        int leftSum     = (col1 > 0) ? prefixMat[row2][col1 - 1] : 0;
        int topLeftSum  = (row1 > 0 && col1 > 0) ? prefixMat[row1 - 1][col1 - 1] : 0;

        return prefixMat[row2][col2] - topSum - leftSum + topLeftSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */