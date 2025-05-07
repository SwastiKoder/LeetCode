class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
                temp = temp->next;
            } else {
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        if (a == NULL) {
            temp->next = b;
        } else {
            temp->next = a;
        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        while (lists.size() > 1) {
            ListNode* a = lists[0];
            lists.erase(lists.begin()) ;
            ListNode* b = lists[0];
            lists.erase(lists.begin()) ;
            ListNode* c = merge(a, b);
            lists.push_back(c);
        }
        return lists[0];
    }
};