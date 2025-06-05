class Solution {
public:
    int findMin(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};