class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        if(n==1) return strs[0];
        string s = strs[0], t = strs[n - 1];
        string res="";
        for (int i = 0; i < min(strs[0].size(), strs[n - 1].size()); i++) {
            if (s[i] == t[i])
                res=res+s[i];
            else
                break;
        }
        return res;
    }
};