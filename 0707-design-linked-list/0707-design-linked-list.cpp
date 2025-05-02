class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size || head == NULL)
            return -1;
        else {
            Node* temp = head;
            for (int i = 1; i <= index; i++) {
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void addAtHead(int val) {
        Node* t = new Node(val);
        if (size == 0) {
            head = t;
        } else {
            t->next = head;
            head = t;
        }
        size++;
    }

    void addAtTail(int val) {
        Node* t = new Node(val);
        if (size == 0) {
            head = t;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = t;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index == 0)
            addAtHead(val);
        else if (index == size)
            addAtTail(val);
        else if (index < 0 || index > size)
            return;
        else {
            Node* t = new Node(val);
            Node* temp = head;
            for (int i = 1; i <= index - 1; i++) {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size || head == NULL)
            return;
        else if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        } else {
            Node* temp = head;
            for (int i = 1; i <= index - 1; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */