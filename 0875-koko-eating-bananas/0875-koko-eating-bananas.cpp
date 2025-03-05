class Solution {
public:
    bool check(int mid, vector<int>& piles, int h) {
        long long count = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            if (piles[i] < mid)
                count++;
            else {
                if (piles[i] % mid == 0)
                    count = count + (long long)(piles[i] / mid);
                else
                    count = count + (long long)(piles[i] / mid) + 1;
            }
        }
        if (count > (long long)h)
            return false;
        else
            return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (max < piles[i])
                max = piles[i];
        }
        int lo = 1;
        int hi = max;
        int minSpeed = max;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, piles, h)) {
                minSpeed = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return minSpeed;
    }
};