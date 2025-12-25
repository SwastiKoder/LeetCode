class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int len = INT_MAX;
        int sum = 0;

        int i = 0;

        for (int j = 0; j < n; j++) {

            sum += nums[j];

            while (sum >= target) {
                len = min(len, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};