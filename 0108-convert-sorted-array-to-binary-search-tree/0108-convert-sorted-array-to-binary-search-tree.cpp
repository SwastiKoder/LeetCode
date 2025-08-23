class Solution {
public:
    TreeNode* helper(vector<int>& nums, int lo, int hi) {
        if (lo > hi)
            return NULL;
        int m = (lo + hi) / 2;
        TreeNode* temp = new TreeNode(nums[m]);
        temp->left = helper(nums, lo, m - 1);
        temp->right = helper(nums, m + 1, hi);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return helper(nums, 0, nums.size() - 1);
    }
};