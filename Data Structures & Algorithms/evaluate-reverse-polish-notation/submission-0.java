class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stk = new Stack<>();
        int a = 0, b = 0;
        for (String token: tokens){
            if (token.equals("+")){
                a = stk.pop();
                b = stk.pop();
                stk.push(b + a);
            } else if (token.equals("-")){
                a = stk.pop();
                b = stk.pop();
                stk.push(b - a);
            } else if (token.equals("*")){
                a = stk.pop();
                b = stk.pop();
                stk.push(b * a);
            } else if (token.equals("/")){
                a = stk.pop();
                b = stk.pop(); 
                stk.push(b / a);
            } else {
                stk.push(Integer.parseInt(token));
            }
        }
        return stk.peek();
    }
}
