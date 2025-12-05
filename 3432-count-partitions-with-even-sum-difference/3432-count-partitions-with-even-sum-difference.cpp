class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        int suff = 0;
        int count = 0;

        for (int i = n - 1; i > 0; i--) {
            suff += nums[i];
            if ((pre[i - 1] - suff) % 2 == 0)
                count++;
        }

        return count;
    }
};