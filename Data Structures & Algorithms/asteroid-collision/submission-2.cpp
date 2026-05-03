class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;
        for (int &a : asteroids) {
            while (!stk.empty() && a < 0 && stk.top() > 0) {
                int diff = a + stk.top();
                if (diff < 0) {
                    stk.pop();
                }
                else if (diff > 0) {
                    a = 0;
                } 
                else {
                    a = 0;
                    stk.pop();
                }
            }
            if (a != 0) {
                stk.push(a);
            }
        }
        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top());   stk.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};