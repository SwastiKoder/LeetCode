class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char , int>st;
        unordered_map<char , int>ts;

        for(int i = 0 ; i < s.length() ; i++){
            char c1 = s[i];
            char c2 = t[i];

            if(st.find(c1) != st.end() && st[c1] != c2) return false;
            if(ts.find(c2) != ts.end() && ts[c2] != c1) return false;

            st[c1] = c2;
            ts[c2] = c1;
        }

        return true;
    }
};