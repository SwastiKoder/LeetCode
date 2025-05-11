class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        ListNode* even = new ListNode(-1);
        ListNode* odd = new ListNode(-2);
        ListNode* te = even;
        ListNode* to = odd;
        while (temp != NULL) {
            to->next = temp;
            to = temp;
            temp = temp->next;
            if (temp!=NULL) {
                te->next = temp;
                te = temp;
                temp = temp->next;
            }
        }
        odd = odd->next;
        even = even->next;
        to->next = even;
        te->next = NULL;
        return odd;
    }
};