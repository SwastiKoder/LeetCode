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
    ListNode* findKthNode(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 1; i < k; i++) {
           if(temp) temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        while (temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == NULL) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            ListNode* nh = reverse(temp);
            if (temp == head)
                head = nh;
            else
                prevNode->next = nh;

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};