class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head ;
        ListNode* temp = head ;
        ListNode* b = temp->next->next;

        if(temp == head && head->next!=NULL) head = temp->next ;
        //if(temp->next) temp->next->next = b ;
        
        temp->next->next = temp ;
        temp->next = swapPairs(b) ;
        return head ;
    }
};