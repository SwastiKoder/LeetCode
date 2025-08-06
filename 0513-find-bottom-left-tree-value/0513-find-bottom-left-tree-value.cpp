class Solution {
public:
    int level(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void nthLevel(TreeNode* root, int curr, int level, int& n, bool flag) {
        if (root == NULL)
            return;
        if (curr == level) {
            n = root->val;
            flag = true;
            return;
        }
        if (flag == false)
            nthLevel(root->left, curr + 1, level, n, false);
        if (flag == false && n==INT_MAX)
            nthLevel(root->right, curr + 1, level, n, false);
    }
    int findBottomLeftValue(TreeNode* root) {
        int n = level(root);
        int ans=INT_MAX;
        nthLevel(root, 1, n, ans, false);
        return ans;
    }
};