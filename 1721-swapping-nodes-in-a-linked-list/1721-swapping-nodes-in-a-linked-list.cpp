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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode* temp1 = head;
        while (temp1 != NULL) {
            size++;
            temp1 = temp1->next;
        }
        temp1 = head;
        for (int i = 1; i <= k - 1; i++) {
            temp1 = temp1->next;
        }
        ListNode* temp2 = head;
        for (int i = 1; i <= size - k; i++) {
            temp2 = temp2->next;
        }
        swap((temp1->val), (temp2->val));
        return head;
    }
};