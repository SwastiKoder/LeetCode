class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        if (strs.size() == 1)
            return strs[0];
        if(strs.size() == 0) return " ";

        string first = *strs.begin();
        string last = strs.back();

        string ans;
        for(int i = 0 ; i < last.length() ; i++){
            if(first[i] != last[i]) break;
            ans += first[i];
        }

        return ans;
    }
};