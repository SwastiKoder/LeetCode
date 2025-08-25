class Solution {
public:
    TreeNode* predecessor(TreeNode* root) {
        TreeNode* pred = root->left;
        while (pred->right) {
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key) {
            // case 1 : if node is a child node
            if (root->left == NULL && root->right == NULL)
                return NULL;
            // case 2 : if node is a single child node
            else if (root->left == NULL || root->right == NULL) {
                if (root->left == NULL)
                    return root->right;
                else
                    return root->left;
                // case 3 : node with 2 childrens
            } else {
                TreeNode* pred = predecessor(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
                return root;
            }
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};