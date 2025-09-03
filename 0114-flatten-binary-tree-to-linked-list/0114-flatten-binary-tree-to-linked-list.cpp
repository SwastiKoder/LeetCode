class Solution {
public:
    vector<TreeNode*> v;
    void preorder(TreeNode* root) {
        if (root == NULL)
            return;
        v.push_back(root);
        preorder(root->left);

        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        preorder(root);
        TreeNode* temp = root;
        for (int i = 1; i < v.size(); i++) {
            temp->right = v[i];
            temp->left = NULL;
            temp = temp->right;
        }
        // temp->right->right=NULL;
    }
};