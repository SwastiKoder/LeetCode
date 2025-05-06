
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* list3 = new ListNode(-1);
        ListNode* temp3 = list3;
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                ListNode* temp = new ListNode(temp1->val);
                temp3->next = temp;
                temp3 = temp3->next ;
                temp1 = temp1->next;
            } else {
                ListNode* temp = new ListNode(temp2->val);
                temp3->next = temp;
                temp3 = temp3 ->next ;
                temp2 = temp2->next;
            }
        }
        if (temp1 == NULL) {
            temp3->next = temp2;
        }
        if (temp2 == NULL) {
            temp3->next = temp1;
        }
        list3 = list3->next;
        return list3;
    }
};