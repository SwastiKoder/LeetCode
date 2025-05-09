class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* nh = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return nh;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;

        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n = 1;
        while (temp) {
            if (n == left - 1)
                a = temp;
            if (n == left)
                b = temp;
            if (n == right)
                c = temp;
            if (n == right + 1)
                d = temp;
            temp = temp->next;
            n++;
        }
        if (a)
            a->next = NULL;
        c->next = NULL;
        c = reverse(b);
        if (a)
            a->next = c;
        b->next = d;
        if(a) return c ;
        return head;
    }
};