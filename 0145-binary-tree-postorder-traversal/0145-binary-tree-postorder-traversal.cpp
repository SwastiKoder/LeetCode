class Solution {
public:
vector<int>ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};