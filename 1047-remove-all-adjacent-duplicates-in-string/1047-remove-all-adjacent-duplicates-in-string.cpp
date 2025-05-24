class Solution {
public:
    string removeDuplicates(string s) {
        if (s.length() == 1)
            return s;
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); i++) {
            if (st.size() !=)&&st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        if (st.size() == 0)
            return "";
        string str;
        while (st.size() > 0) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};