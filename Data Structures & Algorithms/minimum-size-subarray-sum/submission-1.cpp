class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, mn = INT_MAX;
        int sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (l <= r && sum >= target) {
                mn = std::min(mn, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return mn != INT_MAX ? mn : 0;
    }
};