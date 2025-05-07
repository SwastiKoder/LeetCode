class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-2);
        ListNode* to = odd;
        ListNode* te = even;
        ListNode* a = head;
        while (a != NULL) {
            to->next = a;
            to = a;
            a = a->next;
            if (a != NULL) {
                te->next = a;
                te = a;
                a = a->next;
            }
        }
        even = even->next;
        odd = odd->next;
        to->next = even;
        te->next = NULL;
        return odd;
    }
};