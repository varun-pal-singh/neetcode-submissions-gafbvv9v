class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>> stk;  // [temperature, i];
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top().first <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                res[i] = stk.top().second - i; // calc
            }
            stk.push({nums[i], i});
        }
        return res;
    }
};
