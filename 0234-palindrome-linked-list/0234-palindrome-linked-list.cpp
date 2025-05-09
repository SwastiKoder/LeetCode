class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next = NULL;
        while (curr != NULL) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* head2 = new ListNode(-1);
        ListNode* temp1 = head;
        ListNode* temp2 = head2;
        while (temp1 != NULL) {
            temp2->next = new ListNode(temp1->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        head2 = head2->next;
        temp2 = head2;
        temp1 = head;
        temp2 = reverse(head2);
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val != temp2->val)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};