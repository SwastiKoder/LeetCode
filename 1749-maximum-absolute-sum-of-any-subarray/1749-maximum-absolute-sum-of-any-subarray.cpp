class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currSum1 = 0, maxSum = INT_MIN;
        int minSum = INT_MAX, currSum2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum1 = max(nums[i], nums[i] + currSum1);
            maxSum = max(maxSum, currSum1);

            currSum2 = min(nums[i], currSum2 + nums[i]);
            minSum = min(minSum, currSum2);
        }

        return max(abs(maxSum), abs(minSum));
    }
};