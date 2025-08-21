class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
           {
            TreeNode* n = new TreeNode(val);
            return n;
           }
        if (root->val > val) {
            if (root->left == NULL) {
                TreeNode* n = new TreeNode(val);
                root->left = n;
                return root;
            }
            insertIntoBST(root->left, val);
        }
        if (root->val < val) {
            if (root->right == NULL) {
                TreeNode* n = new TreeNode(val);
                root->right = n;
                return root;
            }
            insertIntoBST(root->right, val);
        }
     return root;   
    }
};