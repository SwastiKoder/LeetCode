

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int pivot = -1;

        // Finding the pivot using binary search
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi])  // Pivot is in the right half
                lo = mid + 1;
            else
                hi = mid;
        }
        pivot = lo;

        // If array is not rotated, normal binary search
        if (pivot == 0) {
            lo = 0, hi = nums.size() - 1;
        } 
        else if (target >= nums[0] && target <= nums[pivot - 1]) {
            lo = 0;
            hi = pivot - 1;
        } else {
            lo = pivot;
            hi = nums.size() - 1;
        }

        // Standard binary search
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
};
