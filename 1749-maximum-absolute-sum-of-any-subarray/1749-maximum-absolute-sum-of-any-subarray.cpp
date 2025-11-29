class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            currSum = max(nums[i], nums[i] + currSum);
            maxSum = max(maxSum, currSum);
        }

        currSum = 0;
        int minSum = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            currSum = min(nums[i], currSum + nums[i]);
            minSum = min(minSum, currSum);
        }

        return max(abs(maxSum), abs(minSum));
    }
};