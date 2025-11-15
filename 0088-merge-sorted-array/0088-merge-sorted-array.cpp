class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = 0, r = 0;
        while (l < m && r < n) {
            if (nums1[l] > nums2[r]) {
                int x = nums1[l];
                nums1[l] = nums2[r];
                nums2[r] = x;
                sort(nums2.begin(), nums2.end());
                
            }
            l++;
        }
        r = 0;

        while (r < n) {
            nums1[l] = nums2[r];
            r++;
            l++;
        }

        return;
    }
};