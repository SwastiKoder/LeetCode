class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1)
            return true;
        int prev = 0;
        int curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                curr++;
                if ((curr / 2) >= k)
                    return true;
            } else {
                prev = curr;
                curr = 1;
            }
            if (k == min(prev, curr))
                return true;
        }
        if (prev == 0 && (curr / 2) >= k)
            return true;

        return false;
    }
};