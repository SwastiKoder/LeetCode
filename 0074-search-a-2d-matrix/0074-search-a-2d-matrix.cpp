class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0;
        int hi = (m * n) - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int midValue = matrix[mid / n][mid % n];
            if (midValue == target) {
                return true;
                break;
            } else if (midValue > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return false;
    }
};