class Solution {
public:
    int maxOperations(string s) {
        int noo = 0;
        int ops = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                noo++;
            else {
                while (s[i] == s[i + 1])
                    i++;
                ops += noo;
            }
        }

        return ops;
    }
};