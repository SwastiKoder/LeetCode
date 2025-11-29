class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sumArray = accumulate(nums.begin(), nums.end(), 0);
        int maxSum = nums[0], currmax = nums[0];
        int minSum = nums[0], currmin = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            currmax = max(nums[i], currmax + nums[i]);
            maxSum = max(maxSum, currmax);

            currmin = min(nums[i], currmin + nums[i]);
            minSum = min(minSum, currmin);
        }

        if (maxSum < 0)
            return maxSum;
        int circularSum = sumArray - minSum;
        return max(circularSum, maxSum);
    }
};