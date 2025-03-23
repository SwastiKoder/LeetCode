class Solution {
public:
    // int partition(vector<int>& nums, int si, int ei) {
    //     // int pivotIdx = (si + ei) / 2;
    //     // int pivot = nums[pivotIdx];
    //     // int count = 0;
    //     // for (int i = si; i <= ei; i++) {
    //     //     if (i == (si + ei) / 2)
    //     //         continue;
    //     //     if (nums[i] <= pivot)
    //     //         count++;
    //     // }
    //     //  pivotIdx = si + count;
    //     // swap(nums[pivotIdx], nums[(si + ei) / 2]);
    //     // int i = si, j = ei;
    //     // while (i < pivotIdx && j > pivotIdx) {
    //     //     if (nums[i] < nums[pivotIdx])
    //     //         i++;
    //     //    else if (nums[j] > nums[pivotIdx])
    //     //         j--;
    //     //     else if (nums[i] > nums[pivotIdx] && nums[j] <= nums[pivotIdx]) {
    //     //         swap(nums[i], nums[j]);
    //     //         i++;
    //     //         j--;
    //     //     }
    //     // while (i < pivotIdx && nums[i] <= nums[pivotIdx])
    //     //     i++; // Only move when necessary
    //     // while (j > pivotIdx && nums[j] > nums[pivotIdx])
    //     //     j--; // Only move when necessary

    //     // if (i < pivotIdx && j > pivotIdx) {
    //     //     swap(nums[i], nums[j]);
    //     //     i++;
    //     //     j--;
    //     // }
    //     int pivotIdx = (si + ei) / 2;
    //     int pivot = nums[pivotIdx];

    //     // Move pivot to the end
    //     swap(nums[pivotIdx], nums[ei]);

    //     int i = si; // Position for smaller elements
    //     for (int j = si; j < ei; j++) {
    //         if (nums[j] <= pivot) {
    //             swap(nums[i], nums[j]);
    //             i++;
    //         }
    //     }

    //     // Place pivot at its correct position
    //     swap(nums[i], nums[ei]);

    //     return i; // Return the final pivot index

    //     return pivotIdx;
    // }
    // int kthLargest(vector<int>& nums, int k, int si, int ei) {
    //      if (si >= ei) return nums[si];
    //     int n = nums.size();
    //     int pivotIdx = partition(nums, si, ei);
    //     if (pivotIdx == (n - k))
    //         return nums[pivotIdx]; // kth largest = n-k smallest
    //     else if (pivotIdx > (n - k))
    //         return kthLargest(nums, k, si, pivotIdx - 1);
    //     else
    //         return kthLargest(nums, k, pivotIdx + 1, ei);
    // }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        return nums[n-k] ;
    }
};