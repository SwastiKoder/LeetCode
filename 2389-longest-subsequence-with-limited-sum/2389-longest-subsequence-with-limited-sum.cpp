class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        sort(nums.begin(), nums.end());
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        for (int i = 0; i < m; i++) {
            int length = 0;
            for (int j = 0; j < n; j++) {
                if (pre[j] <= queries[i]) {
                    length++;
                }
            }
            ans[i] = length;
        }
        return ans;
    }
};