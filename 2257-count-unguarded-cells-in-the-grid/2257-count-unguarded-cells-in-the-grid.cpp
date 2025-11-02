class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 0;
        }
        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    for (int k = j + 1; k < n; k++) { // right scan
                        if (grid[i][k] == 0 || grid[i][k] == 1)
                            break;
                        else
                            grid[i][k] = 2;
                    }
                    for (int k = j - 1; k >= 0; k--) { // left scan
                        if (grid[i][k] == 0 || grid[i][k] == 1)
                            break;
                        else
                            grid[i][k] = 2;
                    }
                    for (int k = i + 1; k < m; k++) { // down scan
                        if (grid[k][j] == 0 || grid[k][j] == 1)
                            break;
                        else
                            grid[k][j] = 2;
                    }
                    for (int k = i - 1; k >= 0; k--) { // upper scan
                        if (grid[k][j] == 0 || grid[k][j] == 1)
                            break;
                        else
                            grid[k][j] = 2;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1)
                    count++;
            }
        }
        return count;
    }
};