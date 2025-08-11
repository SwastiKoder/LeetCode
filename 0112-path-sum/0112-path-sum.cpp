class Solution {
public:
    void helper(TreeNode* root, int targetSum, int sum, bool& flag) {
        if (root == NULL)
            return;
        sum = sum + root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                flag = true;
                return;
            }
        }
        helper(root->left, targetSum, sum, flag);
        helper(root->right, targetSum, sum, flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool flag = false;
        helper(root, targetSum, sum, flag);
        return flag;
    }
};