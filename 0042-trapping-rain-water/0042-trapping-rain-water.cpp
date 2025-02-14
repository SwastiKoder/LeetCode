class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prev[n];
        prev[0] = -1;
        int max = height[0];
        for (int i = 1; i < n; i++) {
            prev[i] = max;
            if (max < height[i]) {
                max = height[i];
            }
        }
        int next[n];
        next[n - 1] = -1;
        max = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (max < prev[i]) {
                next[i] = max;
            } else
                next[i] = prev[i];
            if (max < height[i]) {
                max = height[i];
            }
        }
       
        int water = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] < next[i]) {
                water = water + (next[i] - height[i]);
            }
        }
        return water;
    }
};