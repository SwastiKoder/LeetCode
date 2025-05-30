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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        int n = 1;
        ListNode* temp = head;
        while (temp->next != NULL) { // we are one step behind from NULL that is
                                     // why we started from n = 1
            n++;
            temp = temp->next;
        }
        ListNode* tail = temp;
        k = k % n;
        if (k == 0)
            return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        for (int i = 1; i <= n - k; i++) {
            temp2 = temp2->next;
        }
        for (int i = 1; i <= n - k - 1; i++) {
            temp1 = temp1->next;
        }
        tail->next = head;
        head = temp1->next;
        temp1->next = NULL;
        tail = temp1;
        return head;
    }
};