class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int fidx = -1;
        int sidx = -1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* Next = head->next->next;
        while (Next) {
            if (curr->val > prev->val && curr->val > Next->val ||
                curr->val < prev->val && curr->val < Next->val) {
                if (fidx == -1)
                    fidx = idx;
                else
                    sidx = idx;
            }
            prev = prev->next;
            curr = curr->next;
            Next = Next->next;
            idx++;
        }
        if (sidx == -1)
            return {-1, -1};
        int maxDis = sidx - fidx;
        idx = 1;
        fidx = -1;
        sidx = -1;
        prev = head;
        curr = head->next;
        Next = head->next->next;
        int minDis = INT_MAX;
        while (Next) {
            if (curr->val > prev->val && curr->val > Next->val ||
                curr->val < prev->val && curr->val < Next->val) {
                if (fidx == -1)
                    fidx = idx;
                else {
                    sidx = idx;
                }
                if (sidx != -1) {
                    minDis = min(minDis, sidx - fidx);
                    fidx = sidx;
                }
            }
            prev = prev->next;
            curr = curr->next;
            Next = Next->next;
            idx++;
        }
        if (minDis == INT_MAX)
            return {-1, -1};
        return {minDis, maxDis};
    }
};