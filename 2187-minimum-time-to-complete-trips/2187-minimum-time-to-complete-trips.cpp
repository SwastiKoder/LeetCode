class Solution {
public:
    bool check(long long mid, vector<int>& time, int totalTrips) {
        // 1 2 3  mid/time[0] = mid/1 + mid/2 + mid/3
        long long trips = 0;
        int n = time.size();
        for (int i = 0; i < n; i++) {
            trips = trips + mid / (long long)time[i];
        }
        if (trips <(long long)totalTrips)
            return false;
        else
            return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int mx = -1;
        for (int i = 0; i < n; i++) {
           mx = max(mx,time[i]);
        }
        long long lo = 1;
        long long hi = (long long)mx * (long long)totalTrips ;
        long long ans = -1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(mid, time, totalTrips)) {
                ans = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return ans;
    }
};