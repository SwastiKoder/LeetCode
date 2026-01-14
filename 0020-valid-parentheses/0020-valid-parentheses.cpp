class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char x : s) {
            if (x == '(' || x == '[' || x == '{')
                st.push(x);
            else if (st.size()) {
                if (x == ')' && st.top() == '(')
                    st.pop();
                else if (x == '}' && st.top() == '{')
                    st.pop();
                else if (x == ']' && st.top() == '[')
                    st.pop();
                else
                    return false;
            } else
                return false;
        }
        if(st.size()) return false;
        return true;
    }
};