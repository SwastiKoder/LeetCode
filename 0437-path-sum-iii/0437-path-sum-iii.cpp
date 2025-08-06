class Solution {
public:
    int count = 0;
    void helper(TreeNode* root, long long targetSum, int &count) {
        if (root == NULL)
            return;
        if (targetSum == root->val) {
            count++;
           // return;
        }
        helper(root->left, targetSum - root->val, count);
        helper(root->right, targetSum - root->val, count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;
        helper(root, (long long)targetSum, count);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};