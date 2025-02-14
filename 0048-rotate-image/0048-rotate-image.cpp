class Solution {
public:
    void transpose(vector<vector<int>>& v) {
        int size = v.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int temp = v[i][j];
                v[i][j] = v[j][i];
                v[j][i] = temp;
            }
        }
        return ;
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        int m = matrix.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0, k = m - 1; j < k; j++, k--) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = temp;
            }
        }
        return  ;
    }
};