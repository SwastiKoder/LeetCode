/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* last = head;
        for (int i = 1; i <= n + 1; i++) {
            if (fast == NULL)
                return head->next;
            fast = fast->next;
        }
        while (fast != NULL) {
            fast = fast->next;
            last = last->next;
        }
        last->next = last->next->next;
        return head;
    }
};