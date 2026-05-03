class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        std::stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (!stk.empty()) {
                int res = 0;
                if (tokens[i] == "+") {
                    int val = stk.top(); stk.pop();
                    int val1 = 0;
                    if (!stk.empty()) {
                        val1 = stk.top(); stk.pop();
                    }
                    res = val1 + val;
                } 
                else if (tokens[i] == "-") {
                    int val = stk.top(); stk.pop();
                    int val1 = 0;
                    if (!stk.empty()) {
                        val1 = stk.top(); stk.pop();
                    }
                    res = val1 - val;
                } 
                else if (tokens[i] == "*") {
                    int val = stk.top(); stk.pop();
                    int val1 = 0;
                    if (!stk.empty()) {
                        val1 = stk.top(); stk.pop();
                    }
                    res = val1 * val;
                } 
                else if (tokens[i] == "/") {
                    int val = stk.top(); stk.pop();
                    int val1 = 0;
                    if (!stk.empty()) {
                        val1 = stk.top(); stk.pop();
                    }
                    res = val1 / val;
                } 
                else {
                    res = stoi(tokens[i]);
                }
                stk.push(res);
            } else {
                // number
                stk.push(stoi(tokens[i]));
            }
        }
        return (!stk.empty()) ? stk.top() : -1;
    }
};
