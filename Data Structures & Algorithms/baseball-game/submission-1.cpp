class Solution {
   public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        int score = 0;
        std::stack<int> stk;

        for (int i = 0; i < n; i++) {
            string ch = operations[i];
            if (!stk.empty() && ch == "+") {
                int last1 = stk.top();
                stk.pop();
                int last2 = 0;
                if (!stk.empty()) {
                    last2 = stk.top();
                    stk.pop();
                }
                stk.push(last2);
                stk.push(last1);
                int sum = last1 + last2;
                stk.push(sum);
            } 
            else if (!stk.empty() && ch == "D") {
                int last1 = stk.top();
                stk.push(2 * last1);
            } 
            else if (!stk.empty() && ch == "C") {
                score -= stk.top();
                stk.pop();
                if (!stk.empty()) score -= stk.top();
            } 
            else {
                int val = stoi(ch);
                stk.push(val);
            }
            score += (!stk.empty()) ? stk.top() : 0;
        }
        return score;
    }
};