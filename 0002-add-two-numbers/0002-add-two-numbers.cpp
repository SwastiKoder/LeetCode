class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* sumans = new ListNode(-1);
        ListNode* ts = sumans;
        int carry = 0;
        while (temp1 || temp2) {
            int val1 = temp1 ? temp1->val : 0;
            int val2 = temp2 ? temp2->val : 0;
            int actual = val1 + val2 + carry;
            carry = actual / 10;
            actual = actual % 10;
            ListNode* temp = new ListNode(actual);
            ts->next = temp;
            ts = temp;
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        if (carry > 0) {
            ListNode* temp = new ListNode(carry);
            ts->next = temp;
            ts = temp;
        }
        sumans = sumans->next;
        return sumans;
    }
};