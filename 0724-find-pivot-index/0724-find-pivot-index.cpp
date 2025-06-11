class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size());
        pre[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = nums[i] + pre[i - 1];
        }
        vector<int> suf(nums.size());
        suf[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            suf[i] = nums[i] + suf[i + 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (pre[i] == suf[i])
                return i;
        }
        return -1;
    }
};