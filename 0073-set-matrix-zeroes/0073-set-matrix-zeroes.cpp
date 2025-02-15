class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<int> row(m, false);
        // vector<int> col(n, false);
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (matrix[i][j] == 0) {
        //             row[i] = true;
        //             col[j] = true;
        //         }
        //     }
        // }
        // for (int i = 0; i < m; i++) {
        //     if (row[i] == true) {
        //         for (int k = 0; k < n; k++)

        //         {
        //             matrix[i][k] = 0;
        //         }
        //     }
        // }
        // for (int j = 0; j < n; j++) {
        //     if (col[j] == true) {
        //         for (int k = 0; k < m; k++) {
        //             matrix[k][j] = 0;
        //         }
        //     }
        // }
        bool zerothRow = false; // no 0 in 0th row
        bool zerothCol = false;        // no 0 in oth col
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                zerothRow = true;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                zerothCol = true;
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int k = 0; k < m; k++) {
                    matrix[k][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int k = 0; k < n; k++) {
                    matrix[i][k] = 0;
                }
            }
        }
        if (zerothRow == true) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (zerothCol == true) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};