class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), k = n - 1;
        int i = 0, cnt = 0;
        while (i <= k) {
            if (nums[i] == val) {
                nums[i] ^= nums[k];
                nums[k] ^= nums[i];
                nums[i] ^= nums[k];
                k--;
                cnt++;
            } else {
                i++;
            }
        }
        return n - cnt;
    }
};