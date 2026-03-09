class Solution {
public:
    int lessEle(vector<vector<int>>& matrix, int val) {
        int n = matrix.size();
        int row = n - 1;
        int col = 0;
        int count = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] > val) {
                row--;
            } else {
                count += (row + 1);
                col++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int lo = matrix[0][0];
        int hi = matrix[n - 1][n - 1];

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            int rank = lessEle(matrix, mid);
           
             if (rank < k)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }
};