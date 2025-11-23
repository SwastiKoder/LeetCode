class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 3 == 0)
            return sum;
        else if (sum % 3 == 1) {

            int mn = INT_MAX;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] % 3 == 1) {
                    mn = min(mn, nums[i]);
                }
            }

            int m = INT_MAX, n = INT_MAX;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] % 3 == 2) {
                    if (nums[i] <= max(m, n)) {
                        if (nums[i] < m) {
                            n = m;
                            m = nums[i];
                        } else if (nums[i] < n)
                            n = nums[i];
                    }
                }
            }

            if (m == INT_MAX || n == INT_MAX)
                return sum - mn;
            return sum - min(mn, m + n);
        } else {

            int mn = INT_MAX;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] % 3 == 2) {
                    mn = min(mn, nums[i]);
                }
            }
            int m = INT_MAX, n = INT_MAX;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] % 3 == 1) {
                    if (nums[i] <= max(m, n)) {
                        if (nums[i] < m) {
                            n = m;
                            m = nums[i];
                        } else if (nums[i] < n)
                            n = nums[i];
                    }
                }
            }

            if (m == INT_MAX || n == INT_MAX)
                return sum - mn;
            return sum - min(mn, m + n);
        }

        return 0;
    }
};