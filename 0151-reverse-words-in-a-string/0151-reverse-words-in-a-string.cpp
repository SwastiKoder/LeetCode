class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        string word;
        stack<string> st;

        while (ss >> word) {
            st.push(word);
            word.clear();
        }

        string ans;

        while (st.size()) {
            ans += st.top();
            st.pop();
            if (st.size() > 0)
                ans += ' ';
        }

        return ans;
    }
};