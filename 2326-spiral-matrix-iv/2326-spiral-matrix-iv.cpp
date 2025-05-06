
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        ListNode* temp = head;
        int minr = 0;
        int maxr = m - 1;
        int minc = 0;
        int maxc = n - 1;
        while (minr <= maxr && minc <= maxc) {
            for (int j = minc; j <= maxc; j++) {
                if (temp == NULL)
                    return ans;
                ans[minr][j] = temp->val;
                temp = temp->next;
            }
            minr++;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = minr; i <= maxr; i++) {
                if (temp == NULL)
                    return ans;
                ans[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--;
            if (minr > maxr || minc > maxc)
                break;
            for (int j = maxc; j >= minc; j--) {
                if (temp == NULL)
                    return ans;
                ans[maxr][j] = temp->val;
                temp = temp->next;
            }
            maxr--;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = maxr; i >= minr; i--) {
                if (temp == NULL)
                    return ans;
                ans[i][minc] = temp->val;
                temp = temp->next;
            }
            minc++;
            if (minr > maxr || minc > maxc)
                break;
        }
        return ans;
    }
};