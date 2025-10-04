class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* a = head;
        Node* b = new Node(-1);
        Node* temp = a;
        Node* d = b;
        while (temp) {
            Node* dummy = new Node(temp->val);
            d->next = dummy;
            temp = temp->next;
            d = d->next;
        }
        b = b->next;
        unordered_map<Node*, Node*> m;
        Node* temp1 = a;
        Node* temp2 = b;
        while (temp1 != NULL) {
            m[temp1] = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        for (auto ele : m) {
            Node* o = ele.first;
            Node* d = ele.second;
            if (o->random == NULL)
                d->random = NULL;
            else {
                if (m.find(o->random) != m.end()) {
                    d->random = m[o->random];
                }
            }
        }
        return b;
    }
};