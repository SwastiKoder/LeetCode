class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2, -1);
        int lo = 0, hi = nums.size() - 1;

        // Finding the first occurrence
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                v[0] = mid;  // Store potential first occurrence
                hi = mid - 1; // Move left to find earlier occurrences
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        lo = 0, hi = nums.size() - 1;

        // Finding the last occurrence
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                v[1] = mid;  // Store potential last occurrence
                lo = mid + 1; // Move right to find later occurrences
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return v;
    }
};
