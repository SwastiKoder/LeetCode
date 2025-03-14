class Solution {
public:
    void parenthesis(vector<string>& s, string str, int n, int op, int cl) {
        if (op == n && cl == n) {
            s.push_back(str);
            return;
        }
        if (op <= n && op >= cl) {
            parenthesis(s, str + '(', n, op + 1, cl);
            parenthesis(s, str + ')', n, op, cl + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s ;
        int op = 0;
        int cl = 0;
        parenthesis(s, "", n, op, cl);
        return s;
    }
};