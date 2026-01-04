class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int maxr = m - 1;
        int maxc = n - 1;

        int minr = 0;
        int minc = 0;

        int count = 0;
        int totalElements = m * n;

        while (minr <= maxr && minc <= maxc) {
            for (int j = minc; j <= maxc; j++) {
                if (count < totalElements)
                    ans.push_back(matrix[minr][j]);
                count++;
            }
            minr++;

            for (int i = minr; i <= maxr; i++) {
                if (count < totalElements)
                    ans.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;

            for (int j = maxc; j >= minc; j--) {
                if (count < totalElements)
                    ans.push_back(matrix[maxr][j]);
                count++;
            }
            maxr--;

            for (int i = maxr; i >= minr; i--) {
                if (count < totalElements)
                    ans.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return ans;
    }
};