class Solution {
public:
    bool isPerfectSquare(int n) {
        // int lo = 0;
        // int hi = n;
        // while (lo <= hi) {
        //     int mid = lo + (hi - lo) / 2;
        //     long long p = n;
        //     long long q = mid;
        //     if ((q * q) == p) {
        //         return true;
        //         break ;
        //     } else if ((q * q) > p) {
        //         hi = mid - 1;
        //     } else
        //         lo = mid + 1;
        // }
        // return false ;
        int root = sqrt(n);
        if ((root * root) == n)
            return true;
        else
            return false;
    }
    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c;
        while (x <= y) {
            if (isPerfectSquare(x) && isPerfectSquare(y)) {
                return true;
                break;
            }

            else if (!isPerfectSquare(y)) {
                y = (int)sqrt(y) * (int)sqrt(y); // har samay y+x = c
                x = c - y;
            } else {
                x = ((int)sqrt(x) + 1) * ((int)sqrt(x) + 1);
                y = c - x;
            }
        }
        return false;
    }
}

;