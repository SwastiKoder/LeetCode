class Solution {
public:
    bool check(vector<int>& nums, int count, int i, int dir) {
        vector<int> copy = nums;
        int idx = i;
        while (idx >= 0 && idx < copy.size() && count > 0) {

            if (copy[idx] > 0) {
                copy[idx]--;
                dir *= -1;

                if (copy[idx] == 0)
                    count--;
            }
            idx += dir;
        }
        return count == 0;
    }
    int countValidSelections(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0)
                count++;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {

                if (check(nums, count, i, -1))
                    res++;

                if (check(nums, count, i, 1))
                    res++;
            }
        }
        return res;
    }
};