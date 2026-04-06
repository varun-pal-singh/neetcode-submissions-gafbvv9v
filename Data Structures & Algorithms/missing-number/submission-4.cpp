class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        int res = n;
        for (int i = 0; i < n; i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};
