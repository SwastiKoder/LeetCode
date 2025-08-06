class Solution {
public:
    vector<vector<int>> ans;
    void helper(TreeNode* root, int targetSum, vector<int> v) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == root->val) {
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        helper(root->left, targetSum - (root->val), v);
       // v.push_back(root->val);
        helper(root->right, targetSum - (root->val), v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        helper(root, targetSum, v);
        return ans;
    }
};