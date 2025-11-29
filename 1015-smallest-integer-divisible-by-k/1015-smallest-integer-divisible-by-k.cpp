class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1)
            return 1;
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int r = 1;
        int len = 1;

        for (int i = 0; i <= k; i++) {
            r = ((r * 10) + 1) % k;
            len++;
            if (r == 0)
                return len;
        }

        return -1;
    }
};