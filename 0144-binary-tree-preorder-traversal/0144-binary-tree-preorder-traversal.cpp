class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
       if(root!=NULL) st.push(root);
        while (st.size()>0) {
            TreeNode* temp = st.top();
            st.pop();
            v.push_back(temp->val);
            if (temp->right)
                st.push(temp->right);
            if (temp->left)
                st.push(temp->left);
        }
        return v;
    }
};