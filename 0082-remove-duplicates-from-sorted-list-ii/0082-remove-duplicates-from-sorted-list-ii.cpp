class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;
        ListNode* temp = head;

        while (temp != NULL) {
            // Check if temp starts a duplicate sequence
            if (temp->next != NULL && temp->val == temp->next->val) {
                int duplicateVal = temp->val;
                // Skip all nodes with this duplicate value
                while (temp != NULL && temp->val == duplicateVal) {
                    temp = temp->next;
                }
                curr->next = temp;
            } else {
                // No duplicate: move both curr and temp forward
                curr = temp;
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};
