class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int correctIdx = nums[i];
            if (i == n - 1) {
                if (nums[n - 1] != n)
                    return n;
            }
            if (correctIdx != i) {
                return i;
                break;
            }
        }
        return 0;
    }
};