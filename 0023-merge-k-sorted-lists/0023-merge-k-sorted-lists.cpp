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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < n; i++) {
            ListNode* head = lists[i];

            while (head) {
                ListNode* temp = head;
                head = head->next;
                temp->next = NULL;
                pq.push(temp);
            }
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while (pq.size()) {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
        }

        return ans->next;
    }
};