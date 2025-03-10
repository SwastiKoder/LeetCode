class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans,
                vector<vector<int>>& finalans, bool flag, int idx) {
        if (idx == nums.size()) {
            finalans.push_back(ans);
            return;
        }
        if (idx == nums.size() - 1) {
            if (flag == true)
                helper(nums, ans, finalans, true, idx + 1);
            ans.push_back(nums[idx]);
            helper(nums, ans, finalans, true, idx + 1);
            return;
        }
        if (nums[idx] == nums[idx + 1]) {
            if (flag == true)
                helper(nums, ans, finalans, true, idx + 1);
            ans.push_back(nums[idx]);
            helper(nums, ans, finalans, false, idx + 1);
        } else {
            if (flag == true)
                helper(nums, ans, finalans, true, idx + 1);
            ans.push_back(nums[idx]);
            helper(nums, ans, finalans, true, idx + 1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> finalans;
        vector<int> ans;
        helper(nums, ans, finalans, true, 0);
        return finalans;
    }
};