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
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root);
        int i = 0;
        while (i < v.size()) {
            if (v[i] == low)
                break;
            i++;
        }
        int sum = 0;
        while (i < v.size()) {
            sum = sum + v[i];
            if (v[i] == high)
                break;
            i++;
        }
        return sum;
    }
};