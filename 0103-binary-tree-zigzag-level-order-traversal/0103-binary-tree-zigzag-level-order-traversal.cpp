class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while (q.size() > 0) {
            int n = q.size();
            vector<int> v;

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }

            if (count % 2 != 0)
                reverse(v.begin(), v.end());
            ans.push_back(v);
            count++;
        }
        return ans;
    }
};