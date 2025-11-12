class Solution {
public:
    string str;
    bool solve(int i, int j) {
        if (i >= j)
            return true;
        if (str[i] == str[j]) {
            return solve(i + 1, j - 1);
        } else
            return false;
    }
    string longestPalindrome(string s) {
        str = s;
        int sp = 0;
        int maxl = INT_MIN;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (solve(i, j) && maxl < j - i + 1) {
                    sp = i;
                    maxl = j - i + 1;
                }
            }
        }
      

        return s.substr(sp , maxl);
    }
};