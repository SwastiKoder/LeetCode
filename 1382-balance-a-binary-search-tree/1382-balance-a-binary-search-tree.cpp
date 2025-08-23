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
    TreeNode* helper(vector<int>& ans, int lo, int hi) {
        if (lo > hi)
            return NULL;
        int mid = (lo + hi) / 2;
        TreeNode* temp = new TreeNode(ans[mid]);
        temp->left = helper(ans, lo, mid - 1);
        temp->right = helper(ans, mid + 1, hi);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return helper(v, 0, v.size() - 1);
    }
};
static const auto _ = [](){ std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
