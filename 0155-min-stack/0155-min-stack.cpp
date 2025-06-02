class MinStack {
public:
    stack<long long> st;
    long long mn;

    MinStack() { mn = LLONG_MAX; }

    void push(int val) {
        long long v = val;
        if (st.empty()) {
            st.push(v);
            mn = v;
        } else if (v >= mn) {
            st.push(v);
        } else {
            st.push(2 * v - mn);
            mn = v;
        }
    }

    void pop() {
        if (st.top() < mn) {
            mn = 2 * mn - st.top();
        }
        st.pop();
    }

    int top() {
        if (st.top() < mn)
            return (int)mn;
        else
            return (int)st.top();
    }

    int getMin() {
        return (int)mn;
    }
};
