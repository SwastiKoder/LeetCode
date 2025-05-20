// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
// };
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step1 create a deep copy without random pointer
        Node* dummy = new Node(-1);
        Node* tempC = dummy;
        Node* temp = head;
        while (temp) {
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;
        // step2 alternate connections
        dummy = new Node(-1);
        Node* a = head;
        Node* b = duplicate;
        Node* tempD = dummy;
        while (a) {
            tempD->next = a;
            a = a->next;
            tempD = tempD->next;
            tempD->next = b;
            b = b->next;
            tempD = tempD->next;
        }
        dummy = dummy->next;
        // step3 assigning random connections
        Node* t1 = dummy; // t1 will traverse in the original list
        while (t1) {
            Node* t2 = t1->next; // t2 will traverse in the duplicate list
            if (t1->random)
                t2->random = t1->random->next;
            t1 = t1->next->next;
        }
        // step4 separating the list
        Node* d1 = new Node(-1);
        Node* d2 = new Node(-2);
        t1 = d1;
        Node* t4 = d2;
        Node* t = head;
        while (t) {
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t4->next = t;
            t = t->next;
            t4 = t4->next;
        }
        t1->next = NULL;
        t4->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;
    }
};