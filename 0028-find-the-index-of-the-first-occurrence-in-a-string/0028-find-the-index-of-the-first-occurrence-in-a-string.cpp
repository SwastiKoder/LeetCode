class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;
        int i = 0, j = 0;
        int start = 0;

        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == needle.size())
                    return i - j;
            } else {
                j = 0;
                i = start;
                start++;
            }
        }

        return -1;
    }
};