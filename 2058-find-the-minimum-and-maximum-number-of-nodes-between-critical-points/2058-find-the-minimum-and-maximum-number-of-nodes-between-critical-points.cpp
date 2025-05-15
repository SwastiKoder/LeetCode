class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        // int size = 0;
        // ListNode* temp = head;
        // while (temp != NULL) {
        //     temp = temp->next;
        //     size++;
        // }
        // if (size <= 2)
        //     return ans;
       ListNode* temp = head;
        ListNode* prev = temp;
        temp = temp->next;
        ListNode* Next = temp->next;
        vector<int> cp;
        int count = 2; // showing the index of critical point
        while (Next != NULL) {
            if (prev->val < temp->val && Next->val < temp->val)
                cp.push_back(count);
            else if (prev->val > temp->val && Next->val > temp->val)
                cp.push_back(count);
            prev = prev->next;
            temp = temp->next;
            Next = Next->next;
            count++;
        }
        if(cp.size()<2) return ans ;
        int maxdis = 0;
        maxdis = cp[cp.size() - 1] - cp[0];
        int mindis = INT_MAX;
        for (int i = 0; i < cp.size() - 1; i++) {
            mindis = min(mindis, cp[i + 1] - cp[i]);
        }
        ans[0] = mindis;
        ans[1] = maxdis;
        return ans;
    }
};