
class Solution {
public:
    void helper(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left != NULL) {
                TreeNode* pred = curr->left;
                while (pred->right != NULL & pred->right != curr)
                    pred = pred->right;
                if (pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                } else if (pred->right == curr) {
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            } else {
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] >= ans[i + 1])
                return false;
        }
        return true;
    }
};