class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* nh = reverse(head);
        ListNode* temp = nh;
        int sum = 0, size = 0;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        temp = nh;
        for (int i = 0; i < size; i++) {
            sum = sum + ((temp->val) * pow(2, i));
            temp = temp->next;
        }
        return sum;
    }
};