class MyQueue {
private:
    stack<int> stk;

    void stk_push(stack<int> &st, int val) {
        if (st.empty()) {
            st.push(val);
            return;
        }
        int top = st.top();
        st.pop();
        stk_push(st, val);
        st.push(top);
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk_push(stk, x); // push this x to the stk bottom
    }
    
    int pop() {
        int val = stk.top();
        stk.pop();
        return val;
    }
    
    int peek() {
        return stk.top();
    }
    
    bool empty() {
        return stk.empty();
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