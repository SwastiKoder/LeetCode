class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* a = temp->next;
            if (temp->child != NULL) {

                Node* c = temp->child;
                temp->child = NULL;
                c = flatten(c); // recursion

                temp->next = c;
                c->prev = temp;
                Node* t = c;
                while (t->next) {
                    t = t->next;
                }
                t->next = a;
               if(a) a->prev = t;
            }
            temp = a;
        }
        return head;
    }
};