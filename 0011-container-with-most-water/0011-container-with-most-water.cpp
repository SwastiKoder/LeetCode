class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxWater = INT_MIN;
        int n = height.size();
        int i = 0, j = n - 1;
        while (i < j) {
            int k = min(height[i], height[j]);
            mxWater = max(mxWater, k * (j - i));
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return mxWater;
    }
};