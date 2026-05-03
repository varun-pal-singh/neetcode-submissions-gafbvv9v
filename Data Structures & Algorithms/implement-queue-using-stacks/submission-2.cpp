class MyQueue {
private:
    stack<int> stk, stk1;

    void insertAtBottom(stack<int> &st, int val) {
        if (st.empty()) {
            st.push(val);
            return;
        }
        int top = st.top();
        st.pop();
        insertAtBottom(st, val);
        st.push(top);
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        if (stk1.empty()) {
            while (!stk.empty()) {
                stk1.push(stk.top());
                stk.pop();
            }
        }
        int res = stk1.top();
        stk1.pop();
        return res;
    }
    
    int peek() {
        if (stk1.empty()) {
            while (!stk.empty()) {
                stk1.push(stk.top());
                stk.pop();
            }
        }
        return stk1.top();
    }
    
    bool empty() {
        return stk.empty() && stk1.empty();
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