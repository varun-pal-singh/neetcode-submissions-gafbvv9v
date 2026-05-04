class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> stk;
        for (int &ast: asteroids) {
            if (ast < 0) {
                int lastSign = (!stk.empty() && stk.top() > 0) ? 1 : -1;
                while (!stk.empty() && lastSign != -1) {
                    if (stk.top() < abs(ast)) {
                        stk.pop();
                    } 
                    else if (stk.top() > abs(ast)) {
                        ast = 0;
                        break;
                    }
                    else {
                        ast = 0;
                        stk.pop();
                        break;
                    }
                    lastSign = (!stk.empty() && stk.top() > 0) ? 1 : -1;
                }
            } 
            if (ast != 0) {
                stk.push(ast);
            }
        }

        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top()); stk.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};