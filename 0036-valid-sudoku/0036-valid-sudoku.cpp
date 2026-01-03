class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row) {
        int col = board[0].size();
        unordered_set<char> s;
        for (int j = 0; j < col; j++) {
            if (board[row][j] == '.')
                continue;
            else if (s.find(board[row][j]) != s.end())
                return false;
            else
                s.insert(board[row][j]);
        }
        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col) {
        int row = board.size();
        unordered_set<char> s;
        for (int i = 0; i < row; i++) {
            if (board[i][col] == '.')
                continue;
            else if (s.find(board[i][col]) != s.end())
                return false;
            else
                s.insert(board[i][col]);
        }
        return true;
    }
    bool isValidGrid(vector<vector<char>>& board, int row, int col) {
        if (row % 3 == 0 && col % 3 == 0) {
            int startRow = row;
            int startCol = col;
            unordered_set<char> s;

            for (int i = startRow; i < startRow + 3; i++) {
                for (int j = startCol; j < startCol + 3; j++) {
                    if (board[i][j] == '.')
                        continue;
                    else if (s.find(board[i][j]) != s.end())
                        return false;
                    else
                        s.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            if (!isValidRow(board, i))
                return false;
            for (int j = 0; j < col; j++) {
                if (!isValidCol(board, j) || !isValidGrid(board, i, j))
                    return false;
            }
        }

        return true;
    }
};