class Solution {
public:
    string simplifyPath(string path) {
        vector<string> helper;
        string curr;

        for (char x : path) {
            if (x == '/') {
                if (curr.length()) {
                    helper.push_back(curr);
                    curr.clear();
                }
            } else {
                curr += x;
            }
        }
        if (curr.length())
            helper.push_back(curr);

        stack<string> st;
        for (string x : helper) {
            if (x == ".")
                continue;
            else if (x =="..") {
                if (st.size())
                    st.pop();
            } else {
                st.push(x);
            }
        }
        helper.clear();

        if (st.size()) {
            helper.push_back(st.top());
            st.pop();
        } else
            return "/";

        while (st.size()) {
            helper.push_back("/");
            helper.push_back(st.top());
            st.pop();
        }
        
        helper.push_back("/");
        reverse(helper.begin() , helper.end());
        string ans;

        for(string x : helper){
            ans += x;
        }
        return ans;
    }
};