class Solution {
public:
    int level(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;
        int left = level(root->left);
        int right = level(root->right);
        int c = left - right;
        if (c < 0)
            c = 0 - c;
        if (c > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
       
    }
};