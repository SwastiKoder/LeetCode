class Solution {
public:
    ListNode* reverselist(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* nh = reverselist(head->next);
        head->next->next = head;
        head->next = NULL;
        return nh;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode* temp = head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
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
        if (c)
            c->next = NULL;
        c = reverselist(b);
        b->next = d;
        if (a)
            a->next = c;
        if (a)
            return head;
        return c;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap = 1;
        while (temp != NULL && temp->next != NULL) {
            ListNode* t = temp->next;
            int remLen = 0;
            for (int i = 1; t != NULL && i <= gap+1; i++) {
                remLen++;
                t = t->next;
            }
            if (remLen < gap + 1)
                gap = remLen - 1;
            if (gap % 2 != 0)
                reverseBetween(temp, 2, 2 + gap);
            gap++;
            for (int i = 1; temp != NULL && i <= gap; i++) {
                temp = temp->next;
            }
        }
        return head;
    }
};