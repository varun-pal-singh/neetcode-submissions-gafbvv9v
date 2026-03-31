class MinStack {

    Stack<Integer> stk;
    Stack<Integer> minStk;

    public MinStack() {
        this.stk = new Stack<>();
        this.minStk = new Stack<>();
    }
    
    public void push(int val) {
        this.stk.push(val);
        if (this.minStk.isEmpty() || this.minStk.peek() >= val){
            this.minStk.push(val);
        }
    }
    
    public void pop() {
        int val = this.stk.pop();
        if (this.minStk.peek() == val){
            this.minStk.pop();
        }
    }
    
    public int top() {
        return this.stk.peek();
    }
    
    public int getMin() {
        return this.minStk.peek();
    }
}
