class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if (root)
            st.push(root);
        vector<int> v;
        while (st.size()) {
            TreeNode* temp = st.top();
            st.pop();
            v.push_back(temp->val);
            if (temp->left)
                st.push(temp->left);
            if (temp->right)
                st.push(temp->right);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};