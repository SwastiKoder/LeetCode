class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = llabs(dividend);
        long long b = llabs(divisor);
        long long count = 0;

        while (a >= b) {
            long long multiple = 1;
            long long temp = b;

            while (a >= (temp << 1)) {
                temp = temp << 1;
                multiple = multiple << 1;
            }

            count += multiple;
            a -= temp;
        }

        if ((dividend < 0) ^ (divisor < 0))
            count = -count;

        return (int)count;
    }
};