class Solution {
public:
    int countHomogenous(string s) {
        int res = 1;
        int count = 1;

        for (int i = 0; i < s.length() - 1; i++) {

            if (s[i] == s[i + 1])
                count++;
            else
                count = 1;
            res = (res + count) % 1000000007;
        }

        return res;
    }
};