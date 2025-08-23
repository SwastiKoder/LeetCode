class Solution {
public:
    vector<int> v;
    void helper(TreeNode* root) {
        if (root == NULL)
            return;
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        return v[k - 1];
    }
};