class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if (nums.empty())
            return 0;

        int maxEl = *max_element(begin(nums), end(nums)) + k;
        vector<int> cum(maxEl + 1, 0);
        for (int ele : nums) {
            cum[ele]++;
        }
        for (int i = 1; i < (int)cum.size(); i++) {
            cum[i] += cum[i - 1];
        }

        int res = 0;
        // include maxEl
        for (int target = 0; target <= maxEl; target++) {
            int l = max(0, target - k);
            int r = min(target + k, maxEl);
            int count =
                cum[r] -
                (l > 0 ? cum[l - 1] : 0); // numbers within [target-k, target+k]
            int targetCount = (target > 0 ? cum[target] - cum[target - 1]
                                          : cum[0]); // frequency of target
            int needOp = count - targetCount;        // other elements in range
            int possibleConversion = min(needOp, numOperations) + targetCount;
            res = max(res, possibleConversion);
        }
        return res;
    }
};
