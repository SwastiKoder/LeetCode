class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int lo, int hi) {
        if (lo > hi)
            return NULL;
        int i = lo + 1;
        while (i <= hi) {
            if (preorder[i] > preorder[lo])
                break;
            i++;
        }
        TreeNode* temp = new TreeNode(preorder[lo]);
        temp->left = helper(preorder, lo + 1, i - 1);
        temp->right = helper(preorder, i, hi);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
};