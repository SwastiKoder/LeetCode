class Solution {
public:
    int numSub(string s) {
        long long count = 0;
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                count++;
                res = (res + count) % 1000000007;
            } else
                count = 0;
        }

        return res;
    }
};