class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* nh = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return nh;
    }
    ListNode* removeNodes(ListNode* head) {
        if (head->next == NULL)
            return head;
        ListNode* head2 = reverse(head);
        ListNode* temp = head2;
        int mx = temp->val;
         temp = temp->next ;
        stack<int> st;
        st.push(mx);
        while (temp) {
            if (temp->val >= mx) {
                mx = temp->val;
                st.push(mx);
            }
            temp = temp->next;
        }
        if(st.size()==1 && head2->val==head2->next->val) return head2 ;
        ListNode* head3 = new ListNode(st.top());
        st.pop();
        ListNode* temp3 = head3;
        while (st.size() > 0) {
            ListNode* t = new ListNode(st.top());
            temp3->next = t;
            temp3 = temp3->next;
            st.pop();
        }
        return head3 ;
    }
};