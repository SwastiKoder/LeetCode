class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        sort(nums.begin(), nums.end()); // O(nlogn)
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        for (int i = 0; i < m; i++) {
            int length = 0;
            //binary search for better TC but we can use loop in loop also
            int lo = 0;
            int hi = n - 1;
            int target = queries[i];
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (pre[mid] <= target) {
                    length = mid + 1;
                    lo = mid + 1;
                } else
                    hi = mid - 1;
            }
            ans[i] = length;
        }
        return ans;
    }
};