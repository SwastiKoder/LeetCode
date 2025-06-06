class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next = NULL;
        while (curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL&& fast->next->next !=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nh = reverse(slow->next);
        ListNode* a = head;
        ListNode* b = nh;
        while (b && a) {
            if (a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};