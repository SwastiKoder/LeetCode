class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int mn = INT_MAX;
        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] > nums[h])
                l = m + 1;
            else {
                mn = min(mn, nums[m]);
                h = m - 1;
            }
        }
        return mn;
    }
};