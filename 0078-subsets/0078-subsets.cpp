class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans,
                vector<vector<int>>&finalans, int idx) {
        if (idx == nums.size()) {
            finalans.push_back(ans);
            return;
        }
        helper(nums, ans, finalans, idx + 1); // exclude current element
        ans.push_back(nums[idx]);
        helper(nums, ans, finalans, idx + 1); // include current element
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int idx = 0;
        vector<int> v;
        vector<vector<int>> finalans;
        helper(nums, v, finalans, 0);
        return finalans;
    }
}

;