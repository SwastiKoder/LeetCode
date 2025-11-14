class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));

        for (int i = 0; i < queries.size(); i++) {
            int row1 = queries[i][0];
            int col1 = queries[i][1];
            int row2 = queries[i][2];
            int col2 = queries[i][3];

            for (int z = row1; z <= row2; z++) {
                diff[z][col1] += 1;
                if (col2 + 1 < n) {
                    diff[z][col2 + 1] -= 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        return diff;
    }
};