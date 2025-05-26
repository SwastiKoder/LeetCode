class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // vector<int>result;
        for (int i = 0; i < nums1.size(); i++) {
            int idx = -1;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == nums1[i]) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1)
                nums1[i] = idx;
            else {
                if (idx == nums2.size() - 1) {
                    nums1[i] = -1;
                    continue;
                }
                for (int k = idx + 1; k < nums2.size(); k++) {
                    if (nums2[k] > nums1[i]) {
                        nums1[i] = nums2[k];
                        break;
                    } else
                        nums1[i] = -1;
                }
            }
        }
        return nums1;
    }
};