class Solution {
public:
    int sum = 0;
    void helper(TreeNode* root) {
        if (root == NULL)
            return;

        bstToGst(root->right);
        sum = sum + root->val;
        root->val = sum;
        bstToGst(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }
};