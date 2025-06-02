class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ngi(n);
        ngi[n - 1] = n;
        stack<int> st;
        st.push(n-1);
        for (int i = n - 2; i >= 0; i--) {
            while (st.size() != 0 && nums[st.top()] <= nums[i])
                st.pop();
            if (st.size() == 0)
                ngi[i] = n;
            else
                ngi[i] = st.top();
            st.push(i);
        }
        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++) {
            int mx = nums[i];
            int j = i;
            while (j < i + k) { // if nge present inside the window
                mx = nums[j];
                j = ngi[j]; // automatically moves j
            }
            ans.push_back(mx);
        }
        return ans;
    }
};