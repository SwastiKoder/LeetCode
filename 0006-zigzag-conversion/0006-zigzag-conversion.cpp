class Solution {
public:
    string convert(string s, int numRows) {
           if(numRows <= 1) return s;

        vector<string> rows(numRows);

        int row = 0;  // indicating the row of rows = numRows
        int dir = +1; // showing direction to put the element

        for (char x : s) {
            rows[row] += x;
            row += dir;

            if (row == 0) {
                dir = +1;
            } else if (row == numRows - 1) {
                dir = -1;
            }
        }

        string ans;

        for (auto x : rows) {
            ans += x;
        }

        return ans;
    }
};