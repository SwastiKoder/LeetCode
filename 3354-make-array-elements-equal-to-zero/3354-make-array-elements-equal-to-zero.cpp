class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, 0), suffix(n, 0);

        // Compute prefix sum
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        // Compute suffix sum
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] + nums[i];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0)
                continue;

            long long leftSum = (i > 0) ? prefix[i - 1] : 0;
            long long rightSum = (i < n - 1) ? suffix[i + 1] : 0;

            if (leftSum == rightSum)
                ans += 2; // both directions valid
            else if (abs(leftSum - rightSum) == 1)
                ans += 1; // only one direction valid
        }

        return ans;
    }
};