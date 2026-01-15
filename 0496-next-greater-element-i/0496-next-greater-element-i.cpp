class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(m, -1);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = i;
        }

        for (int i = 0; i < m; i++) {
            int idx = -1;
            for (int j = mp[nums1[i]]; j < n; j++) {
                if(nums2[j] > nums1[i]){
                    idx = j;
                    break;
                }
            }
            if(idx != -1) ans[i] = idx;
        }
        return ans;
    }
};