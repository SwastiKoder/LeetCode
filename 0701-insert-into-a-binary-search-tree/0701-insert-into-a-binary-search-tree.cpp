class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* n = new TreeNode(val);
            return n;
        }
        if (root->val > val) {
            if (root->left == NULL) {

                root->left = new TreeNode(val);
                ;
                return root;
            } else
                insertIntoBST(root->left, val);
        } else {
            if (root->right == NULL) {

                root->right = new TreeNode(val);
                return root;
            } else
                insertIntoBST(root->right, val);
        }
        return root;
    }
};