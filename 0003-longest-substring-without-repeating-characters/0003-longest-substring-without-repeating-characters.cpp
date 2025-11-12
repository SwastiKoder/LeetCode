class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        int maxl = 1;

        for (int i = 0; i < s.length(); i++) {
            unordered_set<char> st;

            for (int j = i; j < s.length(); j++) {
                if (st.find(s[j]) == st.end()) {
                    st.insert(s[j]);
                    int n = st.size();
                    maxl = max(maxl, n);

                } else
                    break;
            }
        }

        return maxl;
    }
};