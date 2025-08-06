class Solution {
public:
    int level(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void nthLevel(TreeNode* root, int curr, int level, vector<int>& ans) {
        if (root == NULL)
            return;
        if (curr == level) {
            ans[level]=root->val;
            return;
        }

        nthLevel(root->left, curr + 1, level, ans);
        nthLevel(root->right, curr + 1, level, ans);
    }
    void levelOrder(TreeNode* root, vector<int>& ans) {
        int n = ans.size();
        for (int i = 0; i < n; i++) {
            nthLevel(root, 0, i, ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(level(root), 0);
        levelOrder(root, ans);
        return ans;
    }
};