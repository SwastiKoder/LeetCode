class Solution {
public:
    int reverse(int x) {

        int n = x;
        long long rev = 0;

        while (n != 0) {

            long long p = rev * 10;
            if (p <= INT_MIN || p >= INT_MAX)
                return 0;

            long long y = p + (n % 10);
            if (y <= INT_MIN || y >= INT_MAX)
                return 0;
            rev = y;

            n /= 10;
        }

        return (int)rev;
    }
};