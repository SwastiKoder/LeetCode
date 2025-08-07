class Solution {
public:
    TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& pos,
                    int poslo, int poshi) {
        if (prelo > prehi)
            return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if (prelo == prehi)
            return root;
        int i = poslo;
        while (i <= poshi) {
            if (pos[i] == pre[prelo + 1])
                break;
            i++;
        }
        int leftCount = i - poslo + 1;
        
        root->left = build(pre, prelo + 1, prelo + leftCount, pos, poslo, i);
        root->right =
            build(pre, prelo + 1 + leftCount, prehi, pos, i + 1, poshi - 1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int n = preorder.size();
        TreeNode* root = build(preorder, 0, n - 1, postorder, 0, n - 1);
        return root;
    }
};