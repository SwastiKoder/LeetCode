class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp1 = head->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp2 = dummy;
        int val = 0;
        while (temp1) {
            val = val + temp1->val;

            if (temp1->val == 0) {
                ListNode* a = new ListNode(val);
                temp2->next = a;
                temp2 = temp2->next;
                val = 0;
            }
            temp1 = temp1->next;
        }
        return dummy->next;
    }
};