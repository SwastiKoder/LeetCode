class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)return -1;
        int m = haystack.size();
        int n = needle.size();
        int i = 0;
        int j = 0;
        int start = 0;
        while (i < m && j < n) {
            if (needle[j] == haystack[i]) {
                i++;
                j++;
                if (j == n)
                    return i-j;
            } else {
                j = 0;
                start++;
                i = start;
            }
        }
        return -1;
    }
};