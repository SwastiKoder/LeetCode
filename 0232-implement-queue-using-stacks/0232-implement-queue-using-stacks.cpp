class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    int size;
    MyQueue() { size = 0; }

    void push(int x) {
        st.push(x);
        size++;
    }

    int pop() {
        if (size == 0) {
            return -1;
        }
        while (st.size() > 1) {
            helper.push(st.top());
            st.pop();
        }
        int x = st.top();
        st.pop();
        while (helper.size() > 0) {
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }

    int peek() {
        if (size == 0) {
            return -1;
        }
        while (st.size() > 1) {
            helper.push(st.top());
            st.pop();
        }
        int x = st.top();
        while (helper.size() > 0) {
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }

    bool empty() {
        if(st.size()==0)return true;
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