class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> v(m + n);
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                v[k] = nums1[i];
                i++;

            } else {
                v[k] = nums2[j];

                j++;
            }
            k++;
        }
        if (i == m) {
            while (j < n) {
                v[k] = nums2[j];
                j++;
                k++;
            }
        }
        if (j == n) {
            while (i < m) {
                v[k] = nums1[i];
                k++;
                i++;
            }
        }
        nums1=v;
    }
};