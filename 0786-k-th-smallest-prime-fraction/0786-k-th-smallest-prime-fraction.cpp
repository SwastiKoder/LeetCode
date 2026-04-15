class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans(2);
        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    double a = (double)arr[i] / arr[j];
                    pq.push({a, {arr[i], arr[j]}});
                    if (pq.size() > k)
                        pq.pop();
                }
            }
        }

        ans[0] = pq.top().second.first;
        ans[1] = pq.top().second.second;

        return ans;
    }
};