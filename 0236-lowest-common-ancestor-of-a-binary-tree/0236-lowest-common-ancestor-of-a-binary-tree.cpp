class Solution {
public:
    bool exists(TreeNode* root, TreeNode* target) {
        if (root == NULL)
            return false;
        if (root == target)
            return true;
        return exists(root->left, target) || exists(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root)
            return root;
        else if (exists(root->left, p) && exists(root->right, q))
            return root;
        else if (exists(root->right, p) && exists(root->left, q))
            return root;
        else if (exists(root->left, p) && !exists(root->right, q))
            return lowestCommonAncestor(root->left, p, q);
        else
           return lowestCommonAncestor(root->right, p, q);
    }
};