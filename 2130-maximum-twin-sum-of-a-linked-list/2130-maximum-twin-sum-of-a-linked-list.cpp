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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nh = reverse(slow->next);
        slow->next = NULL;
        ListNode* temp1 = head;
        ListNode* temp2 = nh;
        int tSum = INT_MIN;
        while (temp1 != NULL && temp2 != NULL) {
            int sum = temp1->val + temp2->val;
            tSum = max(sum, tSum);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return tSum;
    }
};