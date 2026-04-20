class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;

        unordered_set<int> seen;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            seen.insert(nums[i]);
            mx = max(mx, nums[i]);
        }

        for (int i = 1; i <= mx; i++) {
            if (seen.find(i) == seen.end()) {
                return i;
            }
        }

        return (mx + 1) <= 0 ? 1 : mx + 1;
    }
};