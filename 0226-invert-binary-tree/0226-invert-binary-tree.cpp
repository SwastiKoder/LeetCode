class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        if (root->left == NULL && root->right == NULL)
            return root;
        if (root->left == NULL) {
            root->left = root->right;
            root->right = NULL;
            return root;
        }
        if (root->right == NULL) {
            root->right = root->left;
            root->left = NULL;
            return root;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};