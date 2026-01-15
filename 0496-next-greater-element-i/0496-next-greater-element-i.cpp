class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> helper(n, -1);
        stack<int> st;
        for (int j = 0; j < n; j++) {
            while (st.size() > 0 && nums2[j] > nums2[st.top()]) {
                helper[st.top()] = nums2[j];
                st.pop();
            }
            st.push(j);
        }

        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++) {
            mp[nums2[j]] = helper[j];
        }

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};