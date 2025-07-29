class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    bool isSame(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;

        if (p->val != q->val)
            return false;
        bool leftAns = isSame(p->left, q->left);
        if (leftAns == false)
            return false;

        bool rightAns = isSame(p->right, q->right);
        if (rightAns == false)
            return false;

        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        invertTree(root->left);
        return isSame(root->left, root->right);
    }
};