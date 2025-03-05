class Solution {
public:
    bool check(int mid, vector<int>& weights, int days) {
        int m = mid;
        int count = 1;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            if (m >= weights[i]) {
                m = m - weights[i];
            } else {
                count++;
                m = mid;
                m = m - weights[i];
            }
        }
        if (count <= days)
            return true;
        else
           return  false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int max = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            if (max < weights[i])
                max = weights[i];
            sum = sum + weights[i];
        }
        int minCapacity = sum;
        int lo = max;
        int hi = sum;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, weights, days)) {
                minCapacity = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return minCapacity;
    }
};