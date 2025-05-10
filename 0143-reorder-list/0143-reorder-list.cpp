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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nh = reverse(slow->next);
        slow->next = NULL;
        ListNode* dummy = new ListNode(-1);
        ListNode* ta = head;
        ListNode* tb = nh;
        ListNode* tc = dummy;
        while (tb) {
            tc->next = ta;
            tc = ta;
            ta = ta->next;
            tc->next = tb;
            tc = tb;
            tb = tb->next;
        }
        if (ta != NULL) {
            tc->next = ta;
            // tc = ta;
            // ta->next = NULL;
        }
        // ta->next = NULL ;
        head = dummy->next;
        return;
    }
};