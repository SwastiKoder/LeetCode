class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int prev = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - k > prev) {
                count++;
                prev = nums[i] - k;
            } else if (prev + 1 <= nums[i] + k) {
                prev++;
                count++;
            }
        }
        return count;
    }
};