class Solution {
public:
    ListNode* findkthnode(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 1; i < k && temp != NULL; i++) {
            temp = temp->next;
        }
        return temp;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v(k);
        int n = 0;
        ListNode* temp = head;

        // Count total number of nodes
        while (temp != NULL) {
            temp = temp->next;
            n++;
        }

        int count = 0;
        int z = 0;
        temp = head;
        ListNode* Next = NULL;

        // Handle extra nodes (n % k parts with 1 extra node)
        while (count < (n % k)) {
            ListNode* kthnode = findkthnode(temp, (n / k) + 1);
            if (kthnode != NULL) {
                Next = kthnode->next;
                kthnode->next = NULL;
            }
            v[z++] = temp;
            temp = Next;
            count++;
        }

        // Handle remaining equal-sized parts
        while (count < k) {
            if (temp == NULL) {
                v[z++] = NULL;
            } else {
                ListNode* kthnode = findkthnode(temp, n / k);
                if (kthnode != NULL) {
                    Next = kthnode->next;
                    kthnode->next = NULL;
                }
                v[z++] = temp;
                temp = Next;
            }
            count++;
        }

        return v;
    }
};
