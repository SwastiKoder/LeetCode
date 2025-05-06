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
        int n = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        k = k % n;
        if (k == 0)
            return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        for (int i = 1; i <= n - k; i++) {
            temp2 = temp2->next;
        }
        for (int i = 1; i <= n - k - 1; i++) {
            temp1 = temp1->next;
        }
        tail->next = head;
        temp1->next = NULL;
        head = temp2;
        tail = temp1;
        return head;
    }
};