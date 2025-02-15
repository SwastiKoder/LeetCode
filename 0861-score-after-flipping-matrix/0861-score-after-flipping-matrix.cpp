class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // making the row started with 0 to 1(flip)
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }
        // flip the column having maximum number of 0
        for (int j = 0; j < n; j++) {
            int noo = 0, noz = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0)
                    noz++;
                else
                    noo++;
            }

            if (noz > noo) {
                for (int i = 0; i < m; i++) {
                    if (grid[i][j] == 0)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }
        // count decimal sum
        int sum = 0;
        for (int i = 0; i < m; i++) {
            int x = 1;
            for (int j = n - 1; j >= 0; j--) {
                sum = sum + grid[i][j] * x;
                x = x * 2;
            }
        }
        return sum;
    }
};