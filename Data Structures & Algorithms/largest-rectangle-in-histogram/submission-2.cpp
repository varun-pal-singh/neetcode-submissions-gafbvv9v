class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk; // monotonic increasing stack
        int maxArea = 0;
        for (int i = 0; i <= n; i++) {
            while (!stk.empty() && (i == n || heights[stk.top()] >= heights[i])) {
                int height = heights[stk.top()];    
                stk.pop();
                int width  = stk.empty() ? i : (i - stk.top()) - 1;
                maxArea    = std::max(maxArea, height * width);
            }
            stk.push(i);
        }

        return maxArea;
    }
};
