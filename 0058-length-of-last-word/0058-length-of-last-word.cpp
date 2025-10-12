class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;
        int i;
        for (i = n - 1; i >= 0;) {
            if (s[i] == ' ')
                i--;
            else
                break;
        }
        for (; i >= 0;) {
            if (s[i] == ' ')
                break;
            else {
                count++;
                i--;
            }
        }
        return count;
    }
};