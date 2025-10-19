class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < lists.size(); i++) {
            ListNode* dummy = lists[i];
            while (dummy) {
                ListNode* prev = dummy;
                dummy = dummy->next;
                prev->next = NULL;
                pq.push(prev);
            }
        }
        if (pq.size() == 0)
            return NULL;
        ListNode* head = pq.top();
        pq.pop();
        ListNode* temp = head;
        while (pq.size()) {
            ListNode* t = pq.top();
            pq.pop();
            temp->next = t;
            temp = temp->next;
        }
        return head;
    }
};