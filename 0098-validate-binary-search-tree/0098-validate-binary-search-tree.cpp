class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for (int i = 0; i < v.size()-1; i++) {
           if(v[i]>=v[i+1])return false;
        }
        return true;
    }
};