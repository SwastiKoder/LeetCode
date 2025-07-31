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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = level(root);
        vector<int> v;
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++) {
            nthLevel(root, 1, i, v);
           
            ans.push_back(v);
             v.clear();
        }
        return ans;
    }
};