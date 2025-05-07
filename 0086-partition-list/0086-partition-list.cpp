
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* a = head;
        ListNode* c = new ListNode(-1);
        ListNode* temp1 = c;
        ListNode* d = new ListNode(-2);
        ListNode* temp2 = d;
        while (a != NULL) {
            if (a->val < x) {
                temp1->next = a;
                temp1 = a;

            } else {
                temp2->next = a;
                temp2 = a;
            }
            a = a->next;
        }
        d = d->next;
        temp1->next = d;
        c = c->next;
        temp2->next = NULL;
        return c;
    }
};