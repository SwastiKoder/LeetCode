class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> helper(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count1 = 0;
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if ((k >= 0 && k < m) && (l >= 0 && l < n)) {
                            if (board[k][l] == 1)
                                count1++;
                        }
                    }
                }

                if (board[i][j] == 1) {
                    if (count1 > 4)
                        helper[i][j] = 0;
                    else if (count1 >= 3)
                        helper[i][j] = 1;
                    else {
                        helper[i][j] = 0;
                    }
                } else {
                    if (count1 == 3)
                        helper[i][j] = 1;
                    else
                        helper[i][j] = 0;
                }
            }
        }
        board = helper;
    }
};