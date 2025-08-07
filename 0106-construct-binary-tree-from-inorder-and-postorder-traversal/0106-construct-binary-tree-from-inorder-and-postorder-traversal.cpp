class Solution {
public:
    TreeNode* build(vector<int>& pos, int poslo, int poshi, vector<int>& in,
                    int inlo, int inhi) {
        if (poslo > poshi)
            return NULL;
        TreeNode* root = new TreeNode(pos[poshi]);
        if (poslo == poshi)
            return root;
        int i=inlo;
        while (i <= inhi) {
            if (in[i] == pos[poshi])
                break;
                i++;
        }
        int leftCount = i - inlo;
        int rightCount = inhi - i;
        root->left = build(pos, poslo, poslo + leftCount - 1, in, inlo, i - 1);
        root->right =
            build(pos, poslo + leftCount, poshi-1, in, i + 1, inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        TreeNode* root = build(postorder, 0, n - 1, inorder, 0, n - 1);
        return root;
    }
};