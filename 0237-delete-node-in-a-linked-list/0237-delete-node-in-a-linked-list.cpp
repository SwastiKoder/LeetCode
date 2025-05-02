/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val ; // just replace the val of the given node and delete its next node
        node->next = node->next->next ;//we can not delete the target node because head node is not given 
    }
};