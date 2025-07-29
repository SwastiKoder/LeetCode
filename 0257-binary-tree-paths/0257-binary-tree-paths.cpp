class Solution {
public:
    void helper(TreeNode* root, string s, vector<string>& ans) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            s = s + to_string(root->val);
            ans.push_back(s);
            return;
        }
        string a = to_string(root->val);
        helper(root->left, s + a + "->", ans);
        helper(root->right, s + a + "->", ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};