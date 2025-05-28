class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1)
            return heights[0];
        vector<int> nsi(n);
        nsi[n - 1] = n;
        stack<int> st;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (st.size() != 0 && heights[st.top()] >= heights[i])
                st.pop();
            if (st.size() == 0)
                nsi[i] = n;
            else
                nsi[i] = st.top();
            st.push(i);
        }
        while (st.size() > 0) {
            st.pop();
        }
        vector<int> psi(n);
        psi[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (st.size() != 0 && heights[st.top()] >= heights[i])
                st.pop();
            if (st.size() == 0)
                psi[i] = -1;
            else
                psi[i] = st.top();
            st.push(i);
        }
        int maxRec = INT_MIN;
        for (int i = 0; i < n; i++) {
            heights[i] = heights[i] * (nsi[i] - psi[i] - 1);
            maxRec = max(maxRec, heights[i]);
        }
        return maxRec;
    }
};