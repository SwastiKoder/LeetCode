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
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        for (int i = 1; i <= k; i++) {
            while (temp2->next != NULL) {
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
            temp2->next = head;
            head = temp2;
            temp1->next = NULL;
            temp1 = head;
            temp2 = head->next;
        }
        return head;
    }
};