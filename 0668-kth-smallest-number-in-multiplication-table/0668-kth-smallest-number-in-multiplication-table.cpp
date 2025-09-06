class Solution {
public:
    int count(int mid, int m, int n) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt = cnt + min(mid / i, n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int lo = 1;
        int hi = m * n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int c = count(mid, m, n);
            if (c < k)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return lo;
    }
};