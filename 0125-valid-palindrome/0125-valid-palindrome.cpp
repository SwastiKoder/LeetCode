class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n <= 1)
            return true;
        int i = 0, j = s.length() - 1;

        while (i <= j) {
            if (isalnum(s[i]) && isalnum(s[j])) {
                if (tolower((unsigned char)s[i]) !=
                    tolower((unsigned char)s[j]))
                    return false;
                else {
                    i++;
                    j--;
                }
            } else if (isalnum(s[i])) {
                j--;
            } else {
                i++;
            }
        }

        return true;
    }
};