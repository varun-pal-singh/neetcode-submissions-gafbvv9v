class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute force
        int n = nums.size();
        // int mx = INT_MIN;
        vector<int> res;
        for (int i = 0; i < (n - k + 1); i++) {
            int mx = INT_MIN;
            for (int j = 0; j < k; j++) {
                mx = std::max(mx, nums[i + j]);
            }
            res.push_back(mx);
        }
        return res;
    }
};
