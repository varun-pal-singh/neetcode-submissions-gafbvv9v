class MinStack {
private:
    stack<int> stk;
    deque<int> deq;
    // int mn = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (deq.empty() || val <= deq.front()) {
            deq.push_front(val);
        }
        else {
            deq.push_back(val);
        }
        // std::cout << "pushed: " << val << "\n";
    }
    
    void pop() {
        if (!stk.empty()) {
            int tp = stk.top();
            int mn  = deq.front();
            if (tp == mn) {
                // std::cout << "removed from deq: " << mn;
                deq.pop_front();
            }
            stk.pop();
            // std::cout << "removed from stk: " << tp;
        }
    }
    
    int top() {
        if (!stk.empty()) {
            return stk.top();
        }
    }
    
    int getMin() {
        if (!stk.empty() && !deq.empty()) {
            return deq.front();
        }
    }
};
