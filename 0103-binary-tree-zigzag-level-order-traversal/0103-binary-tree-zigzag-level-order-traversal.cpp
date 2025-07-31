class Solution {
public:
    int level(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void nthLevel(TreeNode* root, int curr, int level, vector<int>& v) {
        if (root == NULL)
            return;
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        nthLevel(root->left, curr + 1, level, v);
        nthLevel(root->right, curr + 1, level, v);
    }
    void nthLevelrev(TreeNode* root, int curr, int level, vector<int>& v) {
        if (root == NULL)
            return;
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        nthLevelrev(root->right, curr + 1, level, v);
        nthLevelrev(root->left, curr + 1, level, v);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int n = level(root);
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            if (i % 2 != 0)
                nthLevel(root, 1, i, v);
            else
                nthLevelrev(root, 1, i, v);
            ans.push_back(v);
        }
        return ans;
    }
};