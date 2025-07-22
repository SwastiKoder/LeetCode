class MyQueue {
public:
    void insertAtBottom(stack<int>& st, int x) {
        if (st.size() == 0) {
            st.push(x);
            return;
        }
        int y = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(y);
    }
    void reverse(stack<int>& st) {
        if (st.size() == 0)
            return;
        int x = st.top();
        st.pop();
        reverse(st);
        insertAtBottom(st, x);
    }
    stack<int> st1;
    stack<int> st2;
    MyQueue() {}

    void push(int x) { st1.push(x); }

    int pop() {
        while (st1.size() > 1) {
            st2.push(st1.top());
            st1.pop();
        }
        int x = st1.top();
        st1.pop();
        //reverse(st2);
        while (st2.size() > 0) {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }

    int peek() {
        while(st1.size()>1){
            st2.push(st1.top());
            st1.pop();
        }
        int x = st1.top();
        //reverse(st2);
         while (st2.size() > 0) {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }

    bool empty() {
        if(st1.size()==0)return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */